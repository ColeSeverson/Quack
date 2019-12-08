#ifndef TYPECHECKER
#define TYPECHECKER

#include "ASTNode.h"
#include <map>
#include "Structs.h"

namespace TypeChecker {
        int Check(AST::ASTNode *root_, std::map<std::string, struct Structs::Class *> * classes_map, int debug);
}

#endif