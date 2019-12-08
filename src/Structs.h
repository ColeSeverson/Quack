#ifndef STRUCTS
#define STRUCTS
#include <map>
#include "ASTNode.h"


namespace Structs {
    enum isInit {
      unseen, no, yes, unknown  
    };
    //There isn't really a way to define which node a variable references, since it appears multiple times
    struct Var {
        std::string name;
        std::string type;
        isInit init = unseen;
    };
    struct Method {
        AST::Method * node;
        std::string name;
        std::vector<struct Var *> * arguments;
        std::map<std::string, struct Var *> *table;
        std::string returnType;
        std::string originClass;
    };
    struct Class {
        AST::Class * node;
        std::string name;
        std::string super;
        struct Method *constructor;
        std::map<std::string, struct Method *> *methods;
        std::map<std::string, struct Var *> *fields;
        std::vector<std::string> *inherited;
        std::vector<struct Method *> * orderedMethods;
    };
}

#endif