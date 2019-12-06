#include "CodeGen.h"
#include <string>
#include <iostream>
#include "ASTNode.h"
#include "Messages.h"

//This is how we will determine if a variable was already declared or not
struct CodeGenerator::Scope {
    struct CodeGenerator::Scope * parent_scope;
    std::vector<std::string> * variables;
}program_scope;

typedef struct Scope Scope;

void CodeGenerator::debugPrint(std::string statement) {
    if (debug_level == 1) {
        std::cout << "CodeGen: " << statement << std::endl;
    }
}
CodeGenerator::CodeGenerator(AST::ASTNode * root, int debugLevel) {
    //Set up the stuff we need
    this->root = dynamic_cast<AST::Program *>(root);
    this->debug_level = debugLevel;
    this->register_num = 0;
    this->label_num = 0;

    //Instantiate the 'global' scope
    program_scope.variables = new std::vector<std::string>();
    program_scope.parent_scope = NULL;
    debugPrint("Finished constructing the CodeGenerator");
}
CodeGenerator::~CodeGenerator() {
    //CLEANUP TIME
    debugPrint("Deconstructor finished");
}

//Here are methods that are only used internally
void CodeGenerator::generateInitial(std::ofstream &object_code) {
    debugPrint("Entering generateInitial");
    object_code << "#include \"Builtins.h\"" << std::endl;
}

//For LEXPR this needs class and method for context to pass to and rexpr that must be evaled
std::string CodeGenerator::generateLExpr(std::ofstream &object_code, std::string method, std::string clazz, Scope * current_scope, AST::LExpr *lexpr) {
    //Here we need to handle x.y or this.y or x
    int reg;
    switch(lexpr->getType()) {
        case AST::lexprTypes::IDENT:
            {
                debugPrint("Found a Ident");
                AST::Ident * ident = dynamic_cast<AST::Ident *>(lexpr);
                return ident->getText();
                break;
            }
        case AST::lexprTypes::DOT:
            {
                debugPrint("Found a DOT");
                AST::Dot * dot = dynamic_cast<AST::Dot *>(lexpr);
                std::string left = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, dot->getLeft());
                std::string right = dot->getRight()->getText();
                return (left + "->" + right);
                break;
            }
        default:
            report::error("Lexpr type unknown");
            break;
    }

    return "";
}

//This should return the name of the generated value
std::string CodeGenerator::generateStatement(std::ofstream &object_code, std::string method, std::string clazz, struct Scope * current_scope, AST::Statement *statement) {
    int reg;
    switch(statement->getType()) {
        //first come the concrete types
        case AST::statementEnum::AND:
            {
                debugPrint("Found an AND");
                break;
            }
        case AST::statementEnum::OR:
            {
                debugPrint("Found an OR");
                break;
            }
        case AST::statementEnum::NOT:
            {
                debugPrint("Found an NOT");
                break;
            }
        case AST::statementEnum::IF:
            {
                debugPrint("Found an IF");


                return "";
                break;
            }
        case AST::statementEnum::WHILE:
            {
                debugPrint("Found an WHILE");

                return "";
                break;
            }
        case AST::statementEnum::RETURN:
            {
                debugPrint("Found a RETURN");
                break;
            }
        case AST::statementEnum::LOAD:
            {
                debugPrint("Found a Load");
                AST::Load * load = dynamic_cast<AST::Load *>(statement);
                return CodeGenerator::generateLExpr(object_code, method, clazz, current_scope, load->getLocation());
                break;
            }
        case AST::statementEnum::ASSIGNDECLARE:
            {
                debugPrint("Found an AssignDeclare");
                //TODO implement
                AST::AssignDeclare * assign = dynamic_cast<AST::AssignDeclare *>(statement);
                std::string type = assign->getExpr()->typeAnnotation;
                std::string rexpr = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, assign->getExpr());
                std::string lexpr = CodeGenerator::generateLExpr(object_code, method, clazz, current_scope, assign->getLexpr());

                //Check if the value is already initialized or not
                std::vector<std::string> * vec = current_scope->variables;
                if(std::find(vec->begin(), vec->end(), lexpr) == vec->end()) {
                    object_code << "obj_" << type << " ";
                    vec->push_back(lexpr);
                }

                object_code << lexpr << " = " << rexpr << ";\n";

                return "";
                break;
            }
        case AST::statementEnum::ASSIGN:
            {
                //In an assign we will return nothing
                debugPrint("Found an Assign");
                AST::Assign * assign = dynamic_cast<AST::Assign *>(statement);
                std::string type = assign->getExpr()->typeAnnotation;
                std::string rexpr = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, assign->getExpr());
                std::string lexpr = CodeGenerator::generateLExpr(object_code, method, clazz, current_scope, assign->getLexpr());

                //Check if the value is already initialized or not
                std::vector<std::string> * vec = current_scope->variables;
                if(std::find(vec->begin(), vec->end(), lexpr) == vec->end()) {
                    object_code << "obj_" << type << " ";
                    vec->push_back(lexpr);
                }
                object_code << lexpr << " = " << rexpr << ";\n";

                return "";
                break;
            }
        case AST::statementEnum::INTCONST:
            {
                debugPrint("Found an INTCONST");
                AST::IntConst * intConst = dynamic_cast<AST::IntConst *>(statement);
                reg = this->getRegisterNum();
                object_code << "\tobj_Int temp" << reg <<  " = int_literal(" << intConst->getValue() << ");" << std::endl;
                return ("temp" + std::to_string(reg));
                break;
            }
        case AST::statementEnum::STRINGCONST:
            {
                debugPrint("Found an STRINGCONST");
                AST::StrConst * strConst = dynamic_cast<AST::StrConst *>(statement);
                reg = this->getRegisterNum();
                object_code << "\tobj_String temp" << reg << " = str_literal(\"" << strConst->getValue() << "\");" << std::endl;
                return ("temp" + std::to_string(reg));
                break;
            }
        case AST::statementEnum::CONSTRUCT:
            {
                debugPrint("Found an CONSTRUCTOR");
                break;
            }
        case AST::statementEnum::CALL:
            {
                //Call needs to return a temp value containing the value created from the function call
                debugPrint("Found an CALL");
                AST::Call * call = dynamic_cast<AST::Call *>(statement);
                std::string obj = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, call->getReciever());
                std::string method = call->getMethod()->getText();
                std::string returnType = call->typeAnnotation;
                //TODO add actuals
                std::vector<std::string> actuals;
                for(auto actual : call->getArgs()->getElements()) {
                    actuals.push_back(CodeGenerator::generateStatement(object_code, method, clazz, current_scope, actual));
                }

                reg = this->getRegisterNum();

                object_code << "obj_" << returnType << " temp" << reg << " = " << obj << "->" << "clazz" << "->" << method << "(" << obj; 
                
                for(auto actual : actuals) {
                    object_code << ", " << actual;
                }

                object_code <<");" << "\n";

                return ("temp" + std::to_string(reg));
                break;
            }
        default:
            report::error("Statement found does not match any currently implemented types " + std::to_string(statement->getType()));
            exit(256);
    }
    return "";
}
void CodeGenerator::generateMain(std::ofstream &object_code) {
    debugPrint("Entering generateMain");
    object_code << "int main() {\n";

    for(auto node : root->statements_.getElements()) {
        AST::Statement * statement = dynamic_cast<AST::Statement *>(node);
        generateStatement(object_code, "", "Main", &program_scope, statement);
    }

    object_code << "}";
}
//End of internal methods

int CodeGenerator::Generate(std::string fileName) {
    debugPrint("Entering Generate Method");
    std::ofstream object_code(fileName);

    if(object_code.is_open()) {
        debugPrint("Opened file " + fileName);
    } else {
        std::cerr << "Failed to open file " + fileName << std::endl;
        exit(256);
    }

    this->generateInitial(object_code);
    this->generateMain(object_code);

    object_code << "\n\n";
    object_code.flush();
    object_code.close();
    return 0;
}
