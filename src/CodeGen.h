#ifndef CODEGEN
#define CODEGEN

#include "ASTNode.h"
#include <string>
#include <fstream>
#include <map>
#include "Structs.h"

class CodeGenerator {
    private:
        //Private globals variables to keep track of
        AST::Program * root;
        std::string filename;
        int debug_level;
        int register_num;
        int label_num;
        std::map<std::string, struct Structs::Class *> * classes_map;
        
        //Structs
        struct Scope;

        //private methods
        void debugPrint(std::string);
        int getRegisterNum() {return register_num++;};
        int getLabelNum() {return label_num++;};
        bool isInScope(std::string, struct Scope *);
        bool isBuiltIn(std::string);

        //Generators
        void generateInitial(std::ofstream &);
        void generateMain(std::ofstream &);
        void generateClassForwardDecls(std::ofstream &);
        void generateClassDecls(std::ofstream &);
        void generateClassMethods(std::ofstream &, struct Structs::Class *);
        void generateConstructor(std::ofstream &, struct Structs::Class *);
        void generateClass(std::ofstream &, struct Structs::Class *);
        void bindClassMethods(std::ofstream &, struct Structs::Class *);

        //Generators Cont
        std::string generateStatement(std::ofstream &, std::string, std::string, struct Scope *, AST::Statement *);
        std::string generateLExpr(std::ofstream &, std::string, std::string, std::string,  struct Scope *, AST::LExpr *);

    public:
        CodeGenerator(AST::ASTNode * root, std::map<std::string, struct Structs::Class *> * classes_map, int debugLevel);
        ~CodeGenerator();
        int Generate(std::string fileName);
};


#endif