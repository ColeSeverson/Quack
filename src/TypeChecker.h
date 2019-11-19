#ifndef TYPECHECKER
#define TYPECHECKER

#include "ASTNode.h"

namespace TypeChecker {
    int CheckTypes(AST::ASTNode *root);
}

#endif