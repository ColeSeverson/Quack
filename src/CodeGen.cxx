#include "CodeGen.h"
#include <string>
#include <iostream>
#include "ASTNode.h"
#include "Messages.h"

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
//This should return the name of the generated value
std::string CodeGenerator::generateStatement(std::ofstream &object_code, std::string method, std::string clazz, AST::Statement *statement) {
    int reg;
    switch(statement->getType()) {
        //first come the concrete types
        case AST::statementEnum::INTCONST:
            {
            AST::IntConst * intConst = dynamic_cast<AST::IntConst *>(statement);
            reg = this->getRegisterNum();
            object_code << "\tobj_Int intTemp" << reg <<  " = int_literal(" << intConst->getValue() << ");" << std::endl;
		    return ("intTemp" + std::to_string(reg));
            break;
            }
        case AST::statementEnum::STRINGCONST:
            {
            AST::StrConst * strConst = dynamic_cast<AST::StrConst *>(statement);
            reg = this->getRegisterNum();
            object_code << "\tobj_String stringTemp" << reg << " = str_literal(\"" << strConst->getValue() << "\");" << std::endl;
            break;
            }
        default:
            report::error("Statement found does not match any currently implemented types");
            exit(256);
    }
    return "";
}
void CodeGenerator::generateMain(std::ofstream &object_code) {
    debugPrint("Entering generateMain");
    object_code << "int main() {\n";

    for(auto node : root->statements_.getElements()) {
        AST::Statement * statement = dynamic_cast<AST::Statement *>(node);
        generateStatement(object_code, "", "Main", statement);
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
