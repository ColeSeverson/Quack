#include "CodeGen.h"
#include <string>
#include <iostream>

namespace CodeGen {
    int debug = 0;

    void debugPrint(std::string statement) {
        if (debug == 1) {
            std::cout << statement << std::endl;
        }
    }

    int Generate(AST::ASTNode * root, int debugLevel) {
        debug = debugLevel;

        return 0;
    }
}