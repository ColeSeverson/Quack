#include "TypeChecker.h"
#include "ASTNode.h"
#include "Messages.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <map>
#include "Structs.h"

namespace TypeChecker {
    int debugLevel;

    typedef struct Structs::Class Class;
    typedef struct Structs::Method Method;
    typedef struct Structs::Var Var;
    //define structs for managing definitions
    /*enum isInit {
      unseen, no, yes, unknown  
    };
    //There isn't really a way to define which node a variable references, since it appears multiple times
     Var {
        std::string name;
        std::string type;
        isInit init = unseen;
    };
     Method {
        AST::Method * node;
        std::string name;
        std::vector< Var *> * arguments;
        std::map<std::string,  Var *> *table;
        std::string returnType;
    };
     Class {
        AST::Class * node;
        std::string name;
        std::string super;
         Method *constructor;
        std::map<std::string,  Method *> *methods;
        std::map<std::string,  Var *> *fields;
    } Obj, Int, String, Boolean, Nothing;*/
    //Note that you cant have methods outside of a class... So we won't use this methods
    std::map<std::string, Class *> * classes;
    // std::map<std::string, Var *> variables;

    void debugPrint(std::string classs, std::string method, std::string message) {
        if(debugLevel == 1) {
            std::cout << "Class: " << classs << " Method: " << method << " --" << message << std::endl;
        }
    }

    //Vars can be instantiated with type defined or not... If not it will be the empty string
     Var * createVar(AST::Ident * name, AST::Ident * type) {
         Var * output = new  Var();
        output->name = name->getText();
        if(type == NULL) {
            output->type = "";
        } else {
            output->type = type->getText();
        }
        return output;
    }
     Method * createMethod(AST::Method *method) {
        Method * output = new  Method();
        output->name = method->getName()->getText();
        output->node = method;


        std::map<std::string,  Var *> *variables = new std::map<std::string,  Var *>();
        std::vector<Var *> *args = new std::vector<Var *>();
        for(auto argument : method->getFormals()->getElements()) {
            Var * var = new  Var();
            var->name = dynamic_cast<AST::Ident *>(argument->getName())->getText();
            var->type = dynamic_cast<AST::Ident *>(argument->getType())->getText();
            args->push_back(var);
            variables->insert({var->name, var});
        }
        output->arguments = args;
        output->table = variables;

        output->returnType = method->getReturnType()->getText();
        return output;
    }
    int compareMethods( Method * one,  Method * two) {
        //same number of arguments?
        if(one->arguments->size() != two->arguments->size()) {
            //report::error("Method " + one->name + " does not have the same number of arguments as " + two->name);
            return -1;
        }
        //Now we can check argument type
        for(int i = 0; i < one->arguments->size(); i++) {
            if (one->arguments->at(i)->type.compare(two->arguments->at(i)->type) != 0) {
                //report::error("Arguments of " + one->name + " and " + two->name + " do not have the same type");
                return -1;
            }
        }
        if(one->returnType.compare(two->returnType) != 0) {
            return -1;
        }
        return 0;
    }
    int compareVar( Var * one,  Var * two) {
        if(one->type.compare(two->type) != 0) {
            return -1;
        }
        if(one->init != two->init) {
            return -2;
        }
        return 0;
    }
     Class * createClass(AST::Class * clazz) {
        Class * output = new  Class();
        output->node = clazz;
        output->name = clazz->getName()->getText();
        output->super = clazz->getSuper()->getText();
        //The statements associated with a class actually fall into the constructor technically
        output->constructor = createMethod(clazz->getConstructor());

        std::map<std::string,  Var *> *fields = new std::map<std::string,  Var *>();
        output->fields = fields;

        std::map<std::string,  Method *> *methods = new std::map<std::string,  Method *>();
        methods->insert({output->constructor->name, output->constructor});
        for(auto method : clazz->getMethods()->getElements()) {
            std::map<std::string,  Method *>::iterator it = methods->find(method->getName()->getText());
            if(it != methods->end()) {
                report::error("Duplicate method name of " + method->getName()->getText() + " in class " + output->name);
                exit(8);
            }
            methods->insert({method->getName()->getText(), createMethod(method)});
        }
        output->inherited = new std::vector<std::string>();
        output->methods = methods;
        return output;
    }
    //BEGIN HELPER METHODS TO BE REMOVED
    std::string argsInLine(std::vector< Var *> *args) {
        std::string output = "(";
        for(auto arg : *args) {
            output = output + arg->name + ":" + arg->type + ", ";
        }
        output = output + ")";
        return output;
    }
    std::string printVariablesInLine(std::map<std::string,  Var *> *variables) {
        std::string output = "{";
        for(const auto& pair : *variables) {
             Var * var = pair.second;
            output = output + var->name + ":" + var->type;
        }
        return (output = output + "}");
    }
    void printClasses() {
        for(const auto& pair : *classes) {
            if(pair.first.compare("Obj") == 0 || pair.first.compare("Int") == 0 ||
                pair.first.compare("String") == 0 || pair.first.compare("Boolean") == 0 || pair.first.compare("Nothing") == 0) {
                    continue;
            } else {
                std::cout << pair.first << ":" << std::endl;
                std::cout << "  Constructor (" << argsInLine(pair.second->constructor->arguments) << ")" << std::endl;
                std::cout << "  Fields: " << printVariablesInLine(pair.second->fields) << std::endl;
                /*for(const auto& pair2 : *pair.second->methods) {
                    std::cout << "  " << pair2.first << " (" << argsInLine(pair2.second->arguments) << ") : " << pair2.second->returnType << std::endl;
                    std::cout << "      " << printVariablesInLine(pair2.second->table) << std::endl;
                } */
            }
        }
    }

    std::string parseExpr( Class * clazz,  Method * method, AST::Statement * stat);
    //this returns a 'location'
     Var * processLexpr( Class * clazz,  Method * method, AST::LExpr * lExpr) {
        if(lExpr->getType() == AST::lexprTypes::IDENT) {
            debugPrint(clazz->name, method->name, "Found a Lexpr");
            std::string name = ((AST::Ident *)lExpr)->getText();

            if(name.compare("this") == 0) {
                 Var * output = new  Var();
                output->type = clazz->name;
                output->name = clazz->name;
                output->init = Structs::isInit::yes;
                return output;
            }
            if(name.compare("True") == 0 || name.compare("true") == 0) {
                 Var * output = new  Var();
                output->name = "True";
                output->type = "Boolean";
                output->init = Structs::isInit::yes;
                return output;
            }
            if(name.compare("False") == 0 || name.compare("false") == 0) {
                 Var * output = new  Var();
                output->name = "False";
                output->type = "Boolean";
                output->init = Structs::isInit::yes;
                return output;
            }

            //check if it already exists in table
            std::map<std::string,  Var *>::iterator it = method->table->find(name);
            if (it == method->table->end()) {
                 Var * output = new  Var();
                output->name = name;
                output->init = Structs::isInit::no;
                method->table->insert({output->name, output});
                return output;
            } else {
                //ie it does already exist
                return it->second;
            }
        }else if (lExpr->getType() == AST::lexprTypes::DOT) {
            //if left side is this and clazz is null error out since that means we are in the global scope
            AST::Dot * dot = dynamic_cast<AST::Dot *>(lExpr);
            
            debugPrint(clazz->name, method->name, "Found a Dot");
            
            std::string name = dot->getRight()->getText();
            //now we need to resolve the location
            std::string object = parseExpr(clazz, method, dot->getLeft());
            //This should result in a var that represents the classname of something
            //lookup the object in the classes table
            std::map<std::string,  Class *>::iterator it = classes->find(object);
            if(it == classes->end()) {
                report::error("Class " + object + " is not valid");
                exit(16);
            } else {
                std::map<std::string,  Var *>::iterator it2 = it->second->fields->find(name);
                if(it2 == it->second->fields->end()) {
                    if(method == clazz->constructor) {
                         Var * output = new  Var();
                        output->name = name;
                        output->init = Structs::isInit::no;
                        clazz->fields->insert({name, output});
                        return output;
                    }
                    report::error("Class " + it->second->name + " doesnt contain field " + name);
                    exit(32);
                } else {
                    return it2->second;
                }
            }

        }
        return 0;
    }

    std::string classIntersect(std::string one, std::string two) {

        return "";
    }
    std::map<std::string,  Var *> * intersect(std::map<std::string,  Var *> * one, std::map<std::string,  Var *> * two) {
        std::map<std::string,  Var *> *output = new std::map<std::string,  Var *>();
        for(const auto& pair : *one) {
             Var * in = new  Var();
            in->name = pair.second->name;
            in->type = pair.second->type;
            in->init = Structs::isInit::unknown;
            std::map<std::string,  Var *>::iterator it = two->find(pair.first);
            if(it != two->end()) {
                in->init = Structs::isInit::yes;
            }
            output->insert({in->name, in});
        }
        for(const auto& pair : *two) {
            //check if it already exists in the map
            std::map<std::string,  Var *>::iterator it2 = output->find(pair.first);
            if(it2 != output->end()) {
                it2->second->init = Structs::isInit::yes;
                continue;
            }
            //otherwise it wasn't in both lists anyway
             Var * in = new  Var();
            in->name = pair.second->name;
            in->type = pair.second->type;
            in->init = Structs::isInit::unknown;
            output->insert({in->name, in});
        }
        return output;
    }
    //END HELPER METHODS TO BE REMOVED
    //This is run in the methods to parse the statments. It also acts as type inference. Needs reference to method, class, and statemtn
    std::string parseExpr( Class * clazz,  Method * method, AST::Statement * stat) {
        debugPrint(clazz->name, method->name, "Entering the parseExpr method");
        //we will have a seperate case for ASSIGN,ASSIGNDECLARE,EXPR,RETURN,IF,WHILE,LOAD,INTCONST,STRINGCONST,CALL,OOF
        if(stat->getType() == AST::statementEnum::INTCONST) {
            debugPrint(clazz->name, method->name, "Found an int const");
            stat->typeAnnotation = "Int";
            return "Int";
        }else if(stat->getType() == AST::statementEnum::STRINGCONST) {
            debugPrint(clazz->name, method->name, "Found a string const");
            stat->typeAnnotation = "String";
            return "String";
        }else if(stat->getType() == AST::statementEnum::ASSIGN) {
            debugPrint(clazz->name, method->name, "Found an Assign");
            //ASSIGN is the most basic case. The left side variable gets the type of the right side. Lexpr can be either a local variable or a field
            //First we get the type from the rexpr
            //Then we resolve the location and name of the lexpr and assign it the type
            AST::Assign *assi = dynamic_cast<AST::Assign *>(stat); 
             Var * location = processLexpr(clazz, method, assi->getLexpr());
            std::string type = parseExpr(clazz, method, assi->getExpr());
    
            if(location->name.compare("True") == 0 || location->name.compare("true") == 0 ||
                location->name.compare("False") == 0 || location->name.compare("false") == 0) {
                    report::error("Cannot assign value to a constant");
                    exit(8);
                }

            std::map<std::string,  Class *>::iterator it = classes->find(location->name);
            if(it != classes->end()) {
                report::error("Variable cannot be named the same as a class");
                exit(32);
            }

            if(location->init == Structs::isInit::no) {
                location->type = type;
                location->init = Structs::isInit::yes;
                debugPrint(clazz->name, method->name, location->name + "is being initialized");
            }else if (location->init == Structs::isInit::yes) {
                if (location->type.compare(type) != 0) {
                    report::error("Type mismatch variable " + location->name + " has type " + location->type + " so you cannot assign a " + type);
                    exit(64);
                } //we dont need to do anything else right now since it is already the right type
            }

            return "Nothing";
        }else if(stat->getType() == AST::statementEnum::ASSIGNDECLARE) {
            debugPrint(clazz->name, method->name, "Found an assigndeclare");
            //ASSIGN is the most basic case. The left side variable gets the type of the right side. Lexpr can be either a local variable or a field
            //First we get the type from the rexpr
            //Then we resolve the location and name of the lexpr and assign it the type
            AST::AssignDeclare *assi = dynamic_cast<AST::AssignDeclare *>(stat); 
            std::string type = parseExpr(clazz, method, assi->getExpr());
             Var * location = processLexpr(clazz, method, assi->getLexpr());
            
            if(location->name.compare("True") == 0 || location->name.compare("true") == 0 ||
                location->name.compare("False") == 0 || location->name.compare("false") == 0) {
                    report::error("Cannot assign value to a constant");
                    exit(8);
            }
            std::map<std::string,  Class *>::iterator it = classes->find(location->name);
            if(it != classes->end()) {
                report::error("Variable cannot be named the same as a class");
                exit(32);
            }

            if(assi->getStaticType()->getText().compare(type) != 0) {
                report::error("Right side of assignment does not evauluate to the static type for " + location->name);
                exit(64);
            }

            if(location->init == Structs::isInit::no) {
                location->type = type;
                location->init = Structs::isInit::yes;
            }else if (location->init == Structs::isInit::yes) {
                if (location->type.compare(type) != 0) {
                    report::error("Type mismatch variable " + location->name + " has type " + location->type + " so you cannot assign a " + type);
                    exit(64);
                } //we dont need to do anything else right now since it is already the right type
            }

            return "Nothing";
        }else if(stat->getType() == AST::statementEnum::LOAD) {
            debugPrint(clazz->name, method->name, "Found a Load");
            AST::Load * load = dynamic_cast<AST::Load *>(stat);

            Var * value = processLexpr(clazz, method, load->getLocation());

            debugPrint(clazz->name, method->name, "Loaded variable " + value->name);
            if(value->init != Structs::isInit::yes) {
                report::error("Loading possible uninitialized variable: " + value->name);
                exit(32);
            }

            stat->typeAnnotation = value->type;
            return value->type;
        }else if(stat->getType() == AST::statementEnum::RETURN) {
           debugPrint(clazz->name, method->name, "Found a return");
           AST::Return * ReturnAST = dynamic_cast<AST::Return *>(stat);

           std::string type = parseExpr(clazz, method, ReturnAST->getExpr());

            /*std::map<std::string,  Class *>::iterator it = classes.find(type);
            if(it == classes.end()) {
                report::error("Invalid return type");
                exit(16);
            }*/

            if(type.compare(method->returnType) != 0) {
                report::error("Bad return type: " + type + " in method " + method->name + " should be a " + method->returnType);
                exit(64);
            } else {
                stat->typeAnnotation = type;
                return type;
            }
        }else if(stat->getType() == AST::statementEnum::CALL) {
            debugPrint(clazz->name, method->name, "Found a call");
            AST::Call * call = dynamic_cast<AST::Call *>(stat);
            
            //first lets make sure the class is good
            std::string classname = parseExpr(clazz, method, call->getReciever()); 
            std::map<std::string,  Class *>::iterator it = classes->find(classname);
            if(it == classes->end()) {
                report::error("Invalid class " + classname);
                exit(16);
            } else {
                //now that the class exists lets check the method and its args
                std::string methodname = call->getMethod()->getText();
                std::map<std::string,  Method *>::iterator it2 = it->second->methods->find(methodname);
                if(it2 == it->second->methods->end()) {
                    report::error("Invalid method " + methodname + " in class " + classname);
                    exit(16);
                } else {
                    //ok the class does have this method
                    //lets check the arguments
                     Method * called = it2->second;
                    std::vector<AST::Expr *> args = call->getArgs()->getElements();
                    if(args.size() != called->arguments->size()) {
                        report::error("Invalid number of arguments for method " + called->name);
                        exit(8);
                    } else {
                        for(int i = 0; i < called->arguments->size(); i++) {
                            if(called->arguments->at(i)->type.compare(parseExpr(clazz, method, args.at(i))) != 0) {
                                report::error("Invalid argument type in method " + called->name + " " + parseExpr(clazz, method, args.at(i)) + " instead of " + called->arguments->at(i)->type);
                                exit(8);
                            }
                        }
                    }
                }
            }
             Method * temp = (*classes)[classname]->methods->at(call->getMethod()->getText());
            stat->typeAnnotation = temp->returnType;
            return temp->returnType;
        }else if (stat->getType() == AST::statementEnum::IF) {
            debugPrint(clazz->name, method->name, "Found an if " + method->name + " " + clazz->name);
            //first things first lets make two copies of the method->table
            
            std::map<std::string,  Var *> *ttrue = new std::map<std::string,  Var *>(*method->table);
            std::map<std::string,  Var *> *tfalse = new std::map<std::string,  Var *>(*method->table);
            std::map<std::string,  Var *> *fieldstrue = new std::map<std::string,  Var *>(*clazz->fields);
            std::map<std::string,  Var *> *fieldsfalse = new std::map<std::string,  Var *>(*clazz->fields);
                    
                       
            debugPrint(clazz->name, method->name, "Finished declaring temp fields and tables");
            AST::If * ifstat = dynamic_cast<AST::If *>(stat);

            if (parseExpr(clazz, method, ifstat->getCondition()).compare("Boolean") != 0) {
                report::error("Condition for if is not a boolean type");
                exit(124);
            } 
            //first we will swap in the true map and parse the true section
            delete(method->table);
            method->table = ttrue;
            delete(clazz->fields);
            clazz->fields = fieldstrue;
            for(const auto& stat : ifstat->getTrueBlock()->getElements()) {
                AST::Statement *expr = dynamic_cast<AST::Statement *>(stat);
                parseExpr(clazz, method, expr);
            }
            debugPrint(clazz->name, method->name, "True Section parsed");

            method->table = tfalse;
            clazz->fields = fieldsfalse;
            if(ifstat->getFalseBlock()) {
                for(const auto& stat : ifstat->getFalseBlock()->getElements()) {
                    AST::Statement *expr = dynamic_cast<AST::Statement *>(stat);
                    parseExpr(clazz, method, expr);
                }
            }
            debugPrint(clazz->name, method->name, "False Section parsed");
            //Now we check intersection
            method->table = intersect(tfalse, ttrue);
            clazz->fields = intersect(fieldstrue, fieldsfalse);
            delete(ttrue);
            delete(tfalse);
            delete(fieldsfalse);
            delete(fieldstrue);
            return "Nothing";

        }else if (stat->getType() == AST::statementEnum::WHILE) {
            debugPrint(clazz->name, method->name, "Found a while");
            AST::While * whilestat = dynamic_cast<AST::While *>(stat);
            std::map<std::string,  Var *> *ttrue = new std::map<std::string,  Var *>(*method->table);
            std::map<std::string,  Var *> *fieldtrue = new std::map<std::string,  Var *>(*clazz->fields);

            auto temp = method->table;
            auto tempfields = clazz->fields;
            method->table = ttrue;
            clazz->fields = fieldtrue;

            if (parseExpr(clazz, method, whilestat->getCondition()).compare("Boolean") != 0) {
                report::error("Condition for while is not a boolean type");
                exit(124);
            } 

            for(auto expr : whilestat->getBody()->getElements()) {
                AST::Statement * stat = dynamic_cast<AST::Statement *>(expr);
                parseExpr(clazz, method, stat);
            }
            method->table = intersect(temp, method->table);
            clazz->fields = intersect(tempfields, fieldtrue);

            return "Nothing";            

        }else if (stat->getType() == AST::statementEnum::AND) {
            debugPrint(clazz->name, method->name, "Found an AND");
            AST::And * statand = dynamic_cast<AST::And *>(stat);
            std::string one = parseExpr(clazz, method,statand->getLeft());
            std::string two = parseExpr(clazz, method, statand->getRight());

            if(one.compare("Boolean") != 0 || two.compare("Boolean") != 0){
                report::error("One or more values in an AND are not booleans");
                exit(64);
            }
            stat->typeAnnotation = "Boolean";
            return "Boolean";
        }else if (stat->getType() == AST::statementEnum::OR) {
            debugPrint(clazz->name, method->name, "Found an OR");
            AST::Or * statand = dynamic_cast<AST::Or *>(stat);
            std::string one = parseExpr(clazz, method,statand->getLeft());
            std::string two = parseExpr(clazz, method, statand->getRight());
            
            if(one.compare("Boolean") != 0 || two.compare("Boolean") != 0){
                report::error("One or more values in an OR are not booleans");
                exit(64);
            }

            stat->typeAnnotation = "Boolean";
            return "Boolean";
        }else if (stat->getType() == AST::statementEnum::NOT) {
            debugPrint(clazz->name, method->name, "Found a Not");
            AST::Not * notstat = dynamic_cast<AST::Not *>(stat);
            if(parseExpr(clazz, method, notstat).compare("Boolean") != 0) {
                report::error("Non boolean value in not statemetn");
                exit(64);
            }
            stat->typeAnnotation = "Boolean";
            return "Boolean";
        
        }else if(stat->getType() == AST::statementEnum::CONSTRUCT) {
            debugPrint(clazz->name, method->name, "Found a Constructor Call");
            //get the constructor from the classes table
            AST::Construct * construct = dynamic_cast<AST::Construct *>(stat);

            std::vector< Var *> actuals;
            for(auto act : construct->getArgs()->getElements()) {
                 Var * var = new  Var();
                var->type = parseExpr(clazz, method, act);
                var->name = "";
                actuals.push_back(var);
            }

            //now lets check to make sure the method call lines up
            std::map<std::string,  Class *>::iterator it = classes->find(construct->getName()->getText());
            if(it == classes->end()) {
                report::error("Constructor name " + construct->getName()->getText() + " is invalid");
                exit(8);
            } else {
                 Method method = {NULL, construct->getName()->getText(), &actuals, NULL, construct->getName()->getText()};
                if(compareMethods(&method, it->second->constructor) != 0) {
                    report::error("Constructor call for " + it->first + " does not have the correct arguments");
                    exit(64);
                } else {
                    stat->typeAnnotation = it->first;
                    return it->first;
                }
            }

        }else if(stat->getType() == AST::statementEnum::EXPR) {
            report::error("This really shouldn't happen... ");
            exit(16);
        }else if(stat->getType() == AST::statementEnum::OOF) {
            report::error("Found an oof... Check the AST");
            exit(256);
        } 

        return "Nothing";
    }

    int parseMethod( Class * parent,  Method * input) {
        /*
        1) Make sure init before use
        2) Fields need to be copied back to class. They are only considered initialized if in the constructor
        */
        bool constructor = false;
        if(parent->name.compare(input->name) == 0) {
            //This is the constructor then
            constructor = true;
            input->returnType = parent->name;
            debugPrint(parent->name, input->name, "Constructor return set to " + input->returnType);
        }

        std::string type = input->returnType;
        std::map<std::string,  Class *>::iterator it = classes->find(type);
        if(it == classes->end() && type.compare("Nothing") != 0 && type.compare("None") != 0) {
            report::error("Invalid return type");
            exit(16);
        }
        //Instantiate the arguments as variables
        for(auto arg : *input->arguments) {
            arg->init = Structs::isInit::yes;
            input->table->insert({arg->name, arg});
        }

        //parse all of the statements
        for(auto node : input->node->getStatements()->getElements()) {
            AST::Statement * statement = dynamic_cast<AST::Statement *>(node);
            parseExpr(parent, input, statement);
        }

        return 0;
    }
    //Method to parse class
    int parseClass(Class * input) {
        debugPrint(input->super, "parseClass", "Class " + input->name + " Super: " + input->super);
        //When pulling the methods from the super lets make sure they don't overlap
        //If they do overlap it must be the same signature!!
        std::vector< Method *> inherited;
        for(const auto& pair : *(*classes)[input->super]->methods) {
            std::map<std::string,  Method *>::iterator it = input->methods->find(pair.first);
            if(it == input->methods->end()) {
                //We don't have this method! Inherit it!
                input->inherited->push_back(pair.first);
                inherited.push_back(pair.second);
            } else {
                //We do have this method... Make sure the signature matches!
                if(compareMethods(it->second, pair.second) == -1) {
                    report::error("Method " + it->first + " attempts to override superclass method but doesn't match signatures...");
                    exit(16);
                }
            }
        }

        //Lets instantiate the class scope for this class. Firstly is the constructor since it may initialize important instance variables
        parseMethod(input, input->constructor);

        //After parsing the constructor lets make sure we have all of the same fields as our parent
        for(const auto& pair : *(*classes)[input->super]->fields) {
            std::map<std::string,  Var *>::iterator it = input->fields->find(pair.first);
            if(it != input->fields->end()) {
                //ie we do have the field
                int comp = compareVar(it->second, pair.second);
                if(comp == -1) {
                    report::error("Type error in fields Class " + input->name + " and super " + input->super + " in variable " + pair.first);
                    exit(64);
                }else if (comp == -2) {
                    report::error("Field " + pair.first + " in class " + input->name + " super " + input->super + " does not have the same initialization level");
                    exit(32);
                }
            }
        }

        //Then all other methods since they may use instance variables
        for(const auto& pair : *input->methods) {
            //Make sure none of the methods match a field name at this point
            std::map<std::string,  Var *>::iterator it = input->fields->find(pair.first);
            if(it != input->fields->end()) {
                report::error("Method " + pair.first + " shares a name with a field in " + input->name);
                exit(32);
            }
             Method * method = pair.second;
            parseMethod(input, method);
        }
        for(auto inh : inherited) {
            input->methods->insert({inh->name, inh});
        }

        std::map<std::string,  Class *>::iterator superit = classes->find(input->super);
        for(const auto& pair : *input->fields) {
            std::map<std::string,  Var *>::iterator varit = superit->second->fields->find(pair.first);
            if(varit != superit->second->fields->end()) {
                if(varit->second->type != pair.second->type) {
                    report::error("The types of the fields of " + input->name + " do not match its super");
                    exit(64);
                }
            }
        }

        for(const auto& pair : *superit->second->fields) {
            std::map<std::string,  Var *>::iterator varit = input->fields->find(pair.first);
            if(varit == input->fields->end()) {
                report::error("Class " + input->name + " does not instantiate all of its super's fields");
                exit(32);
            }
        }

        return 0;
    }
    //We want to check types, duplicate names between classess/methods/variables, methods, class super signatures, and init before use    
    int Check(AST::ASTNode *root_, std::map<std::string, Class *> * classes_map, int debug) {
        debugLevel = debug;
        debugPrint("", "", "Entering Check method");

        classes = classes_map;

        //caste the root
        AST::Program *root = dynamic_cast<AST::Program *>(root_);   
        //we need the base classes for Obj, Int, String, Bool as well as the base methods that these base classes have as well
        std::map<std::string,  Method *> * objMethods = new std::map<std::string,  Method *>(); //TOADD METHODS
        Method * Print = new  Method();
        Print->name = "PRINT";
        Print->returnType = "Obj";
        Print->arguments = new std::vector< Var *>();
        objMethods->insert({Print->name, Print});

        Var * objArg = new Var();
        objArg->type = "Obj";
        Method * Equals = new  Method();
        Equals->name = "EQUALS";
        Equals->returnType = "Boolean";

        std::vector<Var *> *objEqualsArgs = new std::vector<Var *>();
        objEqualsArgs->push_back(objArg);
        Equals->arguments = objEqualsArgs;
        objMethods->insert({"EQUALS", Equals});

        Class * Obj = new Class(); 
        Obj->name = "Obj";
        Obj->super = "Nothing";
        Obj->methods = objMethods;
        Obj->fields = new std::map<std::string,  Var *>();
        //{NULL, "Obj", "Nothing", NULL, objMethods, new std::map<std::string,  Var *>()};

        //Int methods
        std::map<std::string,  Method *> * intMethods = new std::map<std::string,  Method *>(); //TOADD METHODS
         Method * intPlus = new  Method();
        intPlus->name="PLUS";
        intPlus->returnType = "Int";
        intPlus->arguments = new std::vector< Var *>();
         Var * intarg = new  Var();
        intarg->type = "Int";
        intPlus->arguments->push_back(intarg);

         Method * intTimes = new  Method();
        intTimes->name = "TIMES";
        intTimes->returnType = "Int";
        intTimes->arguments = intPlus->arguments;
        intTimes->node = NULL;
        intTimes->table = NULL;

         Method * intEquals = new  Method();
        intEquals->name="EQUALS";
        intEquals->returnType = "Boolean";
        intEquals->arguments = new std::vector< Var *>();
        intEquals->arguments->push_back(intarg);

         Method * intLess = new  Method();
        intLess->name="LESS";
        intLess->returnType = "Boolean";
        intLess->arguments = new std::vector< Var *>();
        intLess->arguments->push_back(intarg);

        Method * intGreater = new Method();
        intGreater->name = "GREATER";
        intGreater->returnType = "Boolean";
        intGreater->arguments = new std::vector< Var *>();
        intGreater->arguments->push_back(intarg);

         Method * intStr = new  Method();
        intStr->name="STR";
        intStr->returnType = "String";
        intStr->arguments = new std::vector< Var *>();

        intMethods->insert({"EQUALS", intEquals});
        intMethods->insert({"TIMES", intTimes});
        intMethods->insert({"PRINT", Print});
        intMethods->insert({"PLUS", intPlus});
        intMethods->insert({"LESS", intLess});
        intMethods->insert({"GREATER", intGreater});
        intMethods->insert({"Str", intStr});
        Class * Int = new Class();
        Int->name = "Int";
        Int->super = "Obj";
        Int->fields = NULL;
        Int->methods = intMethods;
        //Class Int = {NULL, "Int", "Obj", NULL, intMethods, NULL};

        //String methods
        std::map<std::string,  Method *> * stringMethods = new std::map<std::string,  Method *>();
         Var * strarg = new Var();
        strarg->type = "String";

         Method * strStr = new  Method();
        strStr->name="STR";
        strStr->returnType = "String";
        strStr->arguments = new std::vector< Var *>();

         Method * strEquals = new  Method();
        strEquals->name="EQUALS";
        strEquals->returnType = "Boolean";
        strEquals->arguments = new std::vector< Var *>();
        strEquals->arguments->push_back(strarg);

        stringMethods->insert({"STR", strStr});
        stringMethods->insert({"EQUALS", strEquals});
        stringMethods->insert({"PRINT", Print});

        Class * String = new Class();
        String->name = "String";
        String->super = "Obj";
        String->methods = stringMethods;
        //Class String = {NULL, "String", "Obj", NULL, stringMethods, NULL};

        //Boolean methods
        std::map<std::string,  Method *> * booleanMethods = new std::map<std::string,  Method *>();
        Method * boolStr = new  Method();
        boolStr->name="STR";
        boolStr->returnType = "String";
        boolStr->arguments = new std::vector< Var *>();

        booleanMethods->insert({Print->name, Print});
        booleanMethods->insert({"STR", boolStr});
        Class * Boolean = new Class();
        Boolean->name = "Boolean";
        Boolean->super = "Obj";
        Boolean->methods = booleanMethods;
        //Class Boolean = {NULL, "Boolean", "Obj", NULL, booleanMethods, NULL};

        //Nothing
        std::map<std::string,  Method *> * nothingMethods = new std::map<std::string,  Method *>();
         Method * nothingStr = new  Method();
        nothingStr->name="STR";
        nothingStr->returnType = "String";
        nothingStr->arguments = new std::vector< Var *>();
        nothingMethods->insert({"STR", nothingStr});
        Class * Nothing = new Class();
        Nothing->name = "Nothing";
        Nothing->super = "Obj";
        Nothing->methods = nothingMethods;
        //Class Nothing = {NULL, "Nothing", "Obj", NULL, nothingMethods, NULL};
        
        debugPrint("", "", "Finished adding default methods");
        //Now we will create our reference of classes to check and the valid types
        classes->insert({"Obj", Obj});
        classes->insert({"Int", Int});
        classes->insert({"String", String});
        classes->insert({"Boolean", Boolean});
        classes->insert({"Nothing", Nothing});
        for(auto clazz : root->classes_.getElements()) {
            classes->insert({clazz->getName()->getText(), createClass(clazz)});
        }

        //lets get the classes in topological o/rder (sort of)
        //This algorithm is probably very inefficient for large numbers of strings but hey... Who's writing a 2000 class Quack program please don't test this with one Prof Young ;)
        std::vector<std::string> topo;
        topo.push_back(Obj->name);
        bool change = true;
        while(change) {
            change = false;
            //loop through all of the classes adding them to the topo vector only if their super is already in it
            for(const auto& pair : *classes) {
                if (std::find(topo.begin(), topo.end(), pair.second->name) != topo.end()) {
                    continue;
                } else {
                    if (std::find(topo.begin(), topo.end(), pair.second->super) != topo.end()) {
                        topo.push_back(pair.second->name);
                        change = true;
                        //once nothing new needs to be added we are done
                    }else {
                        continue;
                    }
                }
            }
        }
        debugPrint("", "", "Finished topo sorting the classes");
        //Now we have our ''Global'' scope done. A reference to all of the classes added so we can use their constructors

        //Now lets parse those classes! 
        for(auto name : topo) {
             Class * clazz = (*classes)[name];
            if(clazz->name.compare("Obj") == 0 || clazz->name.compare("String") == 0 ||
                clazz->name.compare("Int") == 0 || clazz->name.compare("Boolean") == 0
                    || clazz->name.compare("Nothing") == 0){
                    continue;
                }
            parseClass(clazz);
        }

        debugPrint("", "", "Finished parsing the classes");

        std::map<std::string,  Var *> *scopeVariables = new std::map<std::string,  Var *>();
        std::map<std::string,  Var *> *fieldVariables = new std::map<std::string,  Var *>();
         Method fakeMethod = {NULL, "GlobalFakeMethod", NULL, scopeVariables, "Nothing"};
         Class fakeClazz = {NULL, "Global", "Nothing", NULL, NULL, fieldVariables};
        for(auto node : root->statements_.getElements()) {
            AST::Statement * statement = dynamic_cast<AST::Statement *>(node);
            parseExpr(&fakeClazz, &fakeMethod,  statement);
        }

        debugPrint("","", "Finished parsing the global statements");
        printClasses();
        if(debugLevel == 1)
            std::cout << "Variables in max scope " << printVariablesInLine(scopeVariables) << std::endl;

        return 0;
    }
}