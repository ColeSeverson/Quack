#include "TypeChecker.h"
#include "ASTNode.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <map>

namespace TypeChecker {
    //define structs for managing definitions
    enum isInit {
      unseen, no, yes, unknown  
    };
    struct Var {
        std::string name;
        std::string type;
        isInit init = unseen;
    };
    struct Method {
        AST::Method * node;
        std::string name;
        std::vector<struct Var *> * arguments;
        AST::Block *statments;
        std::string returnType;
    };
    struct Class {
        AST::Class * node;
        std::string name;
        struct Class *super;
        struct Method *constructor;
        std::vector<struct Method *> methods;
        std::vector<struct Var *> variables;
        AST::Block *statements;
    } Obj;
    //Note that you cant have methods outside of a class... So we won't use this methods
    struct Scope {
        std::map<std::string, struct Class *> *classes;
        AST::Block *statments;
    } global;

    //Vars can be instantiated with type defined or not... If not it will be the empty string
    struct Var * createVar(AST::Ident * name, AST::Ident * type) {
        struct Var * output = new struct Var();
        output->name = name->getText();
        if(type == NULL) {
            output->type = "";
        } else {
            output->type = type->getText();
        }
        return output;
    }
    struct Method * createMethod(AST::Method *method) {
        struct Method * output = new struct Method();
        output->name = method->getName()->getText();
        output->node = method;
        output->statments = method->getStatments();

        std::vector<Var *> *args = new std::vector<Var *>();
        for(auto argument : method->getFormals()->getElements()) {
            struct Var * var = new struct Var();
            var->name = dynamic_cast<AST::Ident *>(argument->getName())->getText();
            var->type = dynamic_cast<AST::Ident *>(argument->getType())->getText();
            args->push_back(var);
        }

        output->returnType = method->getReturnType()->getText();
        return output;
    }


    //We want to check types, duplicate names between classess/methods/variables, methods, class super signatures, and init before use    
    int Check(AST::ASTNode *root_) {
        //first things first lets initialize the global scope        
        global.classes = new std::map<std::string, struct Class *>();
        //global.methods = new std::map<std::string, struct Method *>();
        global.variables = new std::map<std::string, struct Var *>();
        //and the base class Obj
        Obj.name = "Obj";
        Obj.super = NULL;
        Obj.constructor = NULL;
        Obj.body = NULL;
        //Now the global scope and base Obj ready it is time to start accepting new stuff
        AST::Program *root = dynamic_cast<AST::Program *>(root_);

        return 0;
    }
}