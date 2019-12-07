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
bool CodeGenerator::isInScope(std::string var, Scope * scope) {
    debugPrint("IsInScope");
    std::vector<std::string> * vec = scope->variables;
    if(std::find(vec->begin(), vec->end(), var) != vec->end()) {
        return true;
    } else {
        if(scope->parent_scope == NULL) {
            return false;
        } else {
            return isInScope(var, scope->parent_scope);
        }
    }
}

//For LEXPR this needs class and method for context to pass to and rexpr that must be evaled
std::string CodeGenerator::generateLExpr(std::ofstream &object_code, std::string type, std::string clazz, std::string method, Scope * current_scope, AST::LExpr *lexpr) {
    //Here we need to handle x.y or this.y or x
    int reg;
    switch(lexpr->getType()) {
        case AST::lexprTypes::IDENT:
            {
                debugPrint("Found a Ident");
                AST::Ident * ident = dynamic_cast<AST::Ident *>(lexpr);

                std::vector<std::string> * vec = current_scope->variables;
                if(!CodeGenerator::isInScope(ident->getText(), current_scope)) {
                    object_code << "obj_" << type << " ";
                    vec->push_back(ident->getText());
                }

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
                AST::And * and_stat = dynamic_cast<AST::And *>(statement);
                std::string cond1 = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, and_stat->getLeft());
                std::string cond2 = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, and_stat->getLeft());
                return cond1 + " && " + cond2;
                break;
            }
        case AST::statementEnum::OR:
            {
                debugPrint("Found an OR");
                AST::Or * or_stat = dynamic_cast<AST::Or *>(statement);
                std::string cond1 = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, or_stat->getLeft());
                std::string cond2 = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, or_stat->getLeft());
                return cond1 + " || " + cond2;
                break;
            }
        case AST::statementEnum::NOT:
            {
                debugPrint("Found an NOT");
                AST::Not * not_stat = dynamic_cast<AST::Not *>(statement);
                std::string cond1 = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, not_stat->getLeft());
                return "!" + cond1;
                break;
            }
        case AST::statementEnum::IF:
            {
                debugPrint("Found an IF");
                AST::If * iff = dynamic_cast<AST::If *>(statement);
                //First things first lets get the temp variable that will contain the condition
                std::string condition = CodeGenerator::generateStatement(object_code, method, clazz,  current_scope, iff->getCondition());
                //Now lets generate the if
                debugPrint("Generating true section");
                object_code << "if (" << condition << " == lit_true" << " ) {\n";
                Scope true_scope;
                true_scope.parent_scope = current_scope;
                true_scope.variables = new std::vector<std::string>();
                for(auto true_node : iff->getTrueBlock()->getElements()) {
                    AST::Statement * true_statement = dynamic_cast<AST::Statement *>(true_node);
                    CodeGenerator::generateStatement(object_code, method, clazz,  &true_scope, true_statement);
                }
            
                if(iff->getFalseBlock()) {
                    debugPrint("Generating False section");
                    object_code << "} else {\n";
                    Scope false_scope;
                    false_scope.parent_scope = current_scope;
                    false_scope.variables = new std::vector<std::string>();
                    for(auto false_node : iff->getFalseBlock()->getElements()) {
                        AST::Statement * false_statement = dynamic_cast<AST::Statement *>(false_node);
                        CodeGenerator::generateStatement(object_code, method, clazz,  &false_scope, false_statement);
                    }

                    //Now we will check for variables defined in both!
                    for(auto false_var : *false_scope.variables) {
                        auto vec = true_scope.variables;
                        if(std::find(vec->begin(), vec->end(), false_var) != vec->end()) {
                            current_scope->variables->push_back(false_var);
                        }
                    }

                    delete(false_scope.variables);
                }
                object_code << "}\n";
                delete(true_scope.variables);


                return "";
                break;
            }
        case AST::statementEnum::WHILE:
            {
                debugPrint("Found an WHILE");
                AST::While * whilestat = dynamic_cast<AST::While *>(statement);

                std::string condition = CodeGenerator::generateStatement(object_code, method, clazz,  current_scope, whilestat->getCondition());

                object_code << "while (" << condition << " == lit_true" << ") {\n";

                Scope while_scope;
                while_scope.parent_scope = current_scope;
                while_scope.variables = new std::vector<std::string>();
                for(auto node : whilestat->getBody()->getElements()) {
                    AST::Statement * while_statement = dynamic_cast<AST::Statement *>(node);
                    CodeGenerator::generateStatement(object_code, method, clazz,  &while_scope, while_statement);
                }

                std::string update_condition = CodeGenerator::generateStatement(object_code, method, clazz,  current_scope, whilestat->getCondition());
                object_code << condition << " = " << update_condition << ";\n";

                object_code << "}\n";

                delete(while_scope.variables);
                return "";
                break;
            }
        case AST::statementEnum::RETURN:
            {
                debugPrint("Found a RETURN");
                AST::Return * returnstat = dynamic_cast<AST::Return *>(statement);
                std::string toreturn = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, returnstat->getExpr());
                object_code << "return " << toreturn << "\n";
                break;
            }
        case AST::statementEnum::LOAD:
            {
                debugPrint("Found a Load");
                AST::Load * load = dynamic_cast<AST::Load *>(statement);
                return CodeGenerator::generateLExpr(object_code, "", method, clazz,  current_scope, load->getLocation());
                break;
            }
        case AST::statementEnum::ASSIGNDECLARE:
            {
                debugPrint("Found an AssignDeclare");
                //TODO implement
                AST::AssignDeclare * assign = dynamic_cast<AST::AssignDeclare *>(statement);
                std::string type = assign->getExpr()->typeAnnotation;
                std::string rexpr = CodeGenerator::generateStatement(object_code, method, clazz, current_scope, assign->getExpr());
                std::string lexpr = CodeGenerator::generateLExpr(object_code, type, method, clazz, current_scope, assign->getLexpr());

                //Check if the value is already initialized or not

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
                std::string lexpr = CodeGenerator::generateLExpr(object_code, type, method, clazz, current_scope, assign->getLexpr());

                //Check if the value is already initialized or not
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
        //This will have to use malloc
        case AST::statementEnum::CONSTRUCT:
            {
                debugPrint("Found an CONSTRUCTOR");
                AST::Construct * constructor = dynamic_cast<AST::Construct *>(statement);
                
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
                debugPrint("    Method: " + method + " return: " + returnType);
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

void generateClassDecls(std::ofstream & object_code, std::vector<AST::Class *> * classes) {
    
}

void generateMethod(std::ofstream & object_code, struct Scope * current_scope,  AST::Method * method) {

}

void generateClass(std::ofstream & object_code, AST::Class * clazz) {

}



void CodeGenerator::generateInitial(std::ofstream &object_code) {
    debugPrint("Entering generateInitial");
    object_code << "#include \"Builtins.h\"" << std::endl;
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

    //Now lets create a vector of just the user added classes
    std::vector<AST::Class *> classes;
    for(auto clazz : root->classes_.getElements()) {
        std::string name = clazz->getName()->getText();
        if(name.compare("Obj") == 0 || name.compare("Nothing") == 0
            || name.compare("String") == 0 || name.compare("Int") == 0
                || name.compare("Boolean") == 0)
            continue;  
        classes.push_back(clazz);
    }
    
    /*
    std::vector<std::string> classes_topo;
    classes_topo.push_back("Nothing");
    classes_topo.push_back("Obj");

    while(classes.size() > 0) {
        for(int i = 0; i < classes.size(); i++) {
            auto clazz = classes[i];
            if(std::find(classes_topo.begin(), classes_topo.end(), clazz->getSuper()->getText()) != classes_topo.end()) {
                //if the super is in the list
                classes_topo.push_back(clazz->getName()->getText());
                classes.erase(classes.begin() + i);
            }
        }
    }
    */
    //Now classes_topo is a topologically (sort of) sorted list of class names that we will use to generate the forward decls
    /*CodeGenerator::generateClassDecls(object_code, &classes);
    for(auto clazz : classes) {
        CodeGenerator::generateClass(object_code, clazz);
    }*/


    this->generateMain(object_code);

    object_code << "\n\n";
    object_code.flush();
    object_code.close();
    return 0;
}
