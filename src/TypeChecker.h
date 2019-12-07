#ifndef TYPECHECKER
#define TYPECHECKER

#include "ASTNode.h"
#include <map>

namespace TypeChecker {
        struct Var;
        struct Class;
        struct Method;
        int Check(AST::ASTNode *root_, int debug);
}

#endif