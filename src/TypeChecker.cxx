#include "TypeChecker.h"
#include "ASTNode.h"
#include "Messages.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <map>

namespace TypeChecker {
    //define structs for managing definitions
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
        AST::Block *statements;
        std::string returnType;
    };
    struct Class {
        AST::Class * node;
        std::string name;
        std::string super;
        AST::Construct *constructor;
        std::map<std::string, struct Method *> *methods;
        std::map<std::string, struct Var *> *variables;
        std::map<std::string, struct Var *> *fields;
    } Obj;
    //Note that you cant have methods outside of a class... So we won't use this methods
    struct Scope {
        std::map<std::string, struct Class *> *classes;
        std::map<std::string, struct Var *> *variables;
    } global;

    //Keep track of valid types. These will be base types + Class names
    std::vector<std::string> validTypes;
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

    //At this point we only really care about the assignment, returns, typecase, or finding the type of the R_expr for the variable tables so we can do typing correctly
    std::map<std::string, struct Var *> * parseStatements(AST::Block *block) {
        std::map<std::string, struct Var *> *output = new std::map<std::string, struct Var *>();

        for(auto node : block->getElements()) {
            //Lets start with easy case: L_Expr: ident = R_expr
            AST::Statement * statement = dynamic_cast<AST::Statement *>(node);
            if(statement->getType() == AST::statementEnum::ASSIGN) {
                std::cout << "ASSIGN" << std::endl;
                AST::Assign * assign = dynamic_cast<AST::Assign *>(statement);
                //ie x : 5; or a : b;
                struct Var * var = new struct Var();
            } else  if(statement->getType() == AST::statementEnum::ASSIGNDECLARE) {
                std::cout << "ASSIGNDECLARE" << std::endl;
            } else  if(statement->getType() == AST::statementEnum::EXPR) {
                std::cout << "EXPR" << std::endl;
            } else  if(statement->getType() == AST::statementEnum::IF) {
                std::cout << "IF" << std::endl;
            } else  if(statement->getType() == AST::statementEnum::LOAD) {
                std::cout << "LOAD" << std::endl;
            } else  if(statement->getType() == AST::statementEnum::RETURN) {
                std::cout << "RETURN" << std::endl;
            } else  if(statement->getType() == AST::statementEnum::WHILE) {
                std::cout << "WHILE" << std::endl;
            } else  if(statement->getType() == AST::statementEnum::OOF) {
                std::cout << "OOF" << std::endl;
            } else {
                std::cout << "Statement type does not compute..." << std::endl;
                exit(128);
            }
        }

        return output;
    }
    int parseConstructor(struct Class * clazz) {
        AST::Construct *constructor = clazz->constructor;
        return 0;
    }
    struct Method * createMethod(AST::Method *method) {
        struct Method * output = new struct Method();
        output->name = method->getName()->getText();
        output->node = method;
        output->statements = method->getStatements();

        std::vector<Var *> *args = new std::vector<Var *>();
        for(auto argument : method->getFormals()->getElements()) {
            struct Var * var = new struct Var();
            var->name = dynamic_cast<AST::Ident *>(argument->getName())->getText();
            var->type = dynamic_cast<AST::Ident *>(argument->getType())->getText();
            args->push_back(var);
        }
        output->arguments = args;

        output->returnType = method->getReturnType()->getText();
        return output;
    }
    struct Class * createClass(AST::Class * clazz) {
        struct Class * output = new struct Class();
        output->node = clazz;
        output->name = clazz->getName()->getText();
        output->super = clazz->getSuper()->getText();
        //The statements associated with a class actually fall into the constructor technically
        output->constructor = clazz->getConstructor();

        std::map<std::string, struct Method *> *methods = new std::map<std::string, struct Method *>();
        for(auto method : clazz->getMethods()->getElements()) {
            std::map<std::string, struct Method *>::iterator it = methods->find(method->getName()->getText());
            if(it != methods->end()) {
                report::error("Duplicate method name of " + method->getName()->getText() + " in class " + output->name);
                exit(16);
            }
            methods->insert({method->getName()->getText(), createMethod(method)});
        }
        //for the fun of it lets insert the constructor into the methods list too
        //methods->insert({clazz->getConstructor()->getName()->getText(), createMethod(clazz->getConstructor())});
        output->methods = methods;
        return output;
    }
    std::string argsInLine(struct Method * method) {
        std::string output = "(";
        for(auto arg : *method->arguments) {
            output = output + arg->name + ":" + arg->type + ", ";
        }
        output = output + ")";
        return output;
    }
    void printTables() {
        std::cout << "Global Table Contents: " << std::endl;
        for(const auto& pair : *global.classes) {
            std::cout << "  " + pair.first + ":" << std::endl;
            for(const auto& pair: *pair.second->methods) {
                std::cout << "      " + pair.first + ": " << argsInLine(pair.second) << std::endl;
                std::cout << "        Return type: " + pair.second->returnType << std::endl;
            }
        }
        std::string types = "";
        for(auto type : validTypes) {
            types = types + type + " ";
        }
        std::cout << "Valid Types: " << types << std::endl;
    }
    int constructTables(AST::Program *root) {
        //first lets construct the table for the global scope
        global.variables = parseStatements(&root->statements_);

        std::map<std::string, struct Class *> *classes = new std::map<std::string, struct Class *>();
        for(auto clazz : root->classes_.getElements()) {
            classes->insert({clazz->getName()->getText(), createClass(clazz)});
            validTypes.push_back(clazz->getName()->getText());
        }
        global.classes = classes;

        return 0;
    }
    //We want to check types, duplicate names between classess/methods/variables, methods, class super signatures, and init before use    
    int Check(AST::ASTNode *root_) {
        //caste the root
        AST::Program *root = dynamic_cast<AST::Program *>(root_);
        //Create the base types 
        validTypes.push_back("Obj");
        validTypes.push_back("Nothing");
        validTypes.push_back("String");
        validTypes.push_back("Boolean");
        validTypes.push_back("Int");      
        //and the base class Obj
        Obj = {NULL, "Obj", "", NULL, new std::map<std::string, struct Method *>(), new std::map<std::string, struct Var *>(), new std::map<std::string, struct Var *>()};
        //Now we must build the class, method, and variable tables for the other checking
        //Global scope is initialized in this method along with everything else
        if(constructTables(root) != 0) {
            report::error("Type Checker failed to construct tables terminating...");
            exit(128);
        }
        //now the tables will be children of global!
        //Lets check if the method signatures and stuff match up



        printTables();

        return 0;
    }
}