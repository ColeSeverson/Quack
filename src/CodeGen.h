#ifndef CODEGEN
#define CODEGEN

#include "ASTNode.h"

namespace CodeGen {
    int Generate(AST::ASTNode * root, int debugLevel);
}

#endif