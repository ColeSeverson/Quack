#ifndef CODEGEN
#define CODEGEN

#include "ASTNode.h"
#include <string>
#include <fstream>

class CodeGenerator {
    private:
        //Private globals variables to keep track of
        AST::Program * root;
        std::string filename;
        int debug_level;
        int register_num;
        int label_num;

        //private methods
        void debugPrint(std::string);
        int getRegisterNum() {return register_num++;};
        int getLabelNum() {return label_num++;};
        void generateInitial(std::ofstream &);
        void generateMain(std::ofstream &);
        std::string generateStatement(std::ofstream &, std::string, std::string, AST::Statement *);

    public:
        CodeGenerator(AST::ASTNode * root, int debugLevel);
        ~CodeGenerator();
        int Generate(std::string fileName);
};


#endif