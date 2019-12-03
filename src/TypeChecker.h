#ifndef TYPECHECKER
#define TYPECHECKER

#include "ASTNode.h"

namespace TypeChecker {
    int Check(AST::ASTNode *root_, int debug);
}

#endif