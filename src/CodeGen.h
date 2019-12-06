#ifndef CODEGEN
#define CODEGEN

#include "ASTNode.h"
#include <string>
#include <fstream>
#include <map>

class CodeGenerator {
    private:
        //Private globals variables to keep track of
        AST::Program * root;
        std::string filename;
        int debug_level;
        int register_num;
        int label_num;
        
        //Structs
        struct Scope;

        //private methods
        void debugPrint(std::string);
        int getRegisterNum() {return register_num++;};
        int getLabelNum() {return label_num++;};
        bool isInScope(std::string, struct Scope *);

        //Generators
        void generateInitial(std::ofstream &);
        void generateMain(std::ofstream &);
        void generateClassDecls(std::ofstream &, std::vector<AST::Class *> *);
        void generateClass(std::ofstream &, AST::Class *);
        void generateMethod(std::ofstream &, struct Scope *, AST::Method *);

        //Generators Cont
        std::string generateStatement(std::ofstream &, std::string, std::string, struct Scope *, AST::Statement *);
        std::string generateLExpr(std::ofstream &, std::string, std::string, std::string,  struct Scope *, AST::LExpr *);

    public:
        CodeGenerator(AST::ASTNode * root, int debugLevel);
        ~CodeGenerator();
        int Generate(std::string fileName);
};


#endif