//
// The parser driver just glues together a parser object
// and a lexer object.
//

#include "lex.yy.h"
#include "ASTNode.h"
#include "Messages.h"
#include "ClassChecker.h"
#include "TypeChecker.h"
#include "CodeGen.h"

#include <iostream>
#include <unistd.h>  // getopt is here

class Driver {
    int debug_level = 0;
public:
    explicit Driver(const reflex::Input in) : lexer(in), parser(new yy::parser(lexer, &root)) { root = nullptr; }

    ~Driver() { delete parser; }

    void debug() { debug_level = 1; }

    AST::ASTNode *parse() {
        parser->set_debug_level(debug_level); // 0 = no debugging, 1 = full tracing
        // std::cout << "Running parser\n";
        int result = parser->parse();
        if (result == 0 && report::ok()) {  // 0 == success, 1 == failure
            // std::cout << "Extracting result\n";
            if (root == nullptr) {
                std::cout << "But I got a null result!  How?!\n";
            }
            return root;
        } else {
            // std::cout << "Parse failed, no tree\n";
            return nullptr;
        }
    }

private:
    yy::Lexer lexer;
    yy::parser *parser;
    AST::ASTNode *root;
};

int main(int argc, char **argv) {
    std::string filename;
    char c;
    FILE *f;
    int index;
    int debug = 1; // 0 = no debugging, 1 = full tracing
    int json = 0;
    int type = 1;
    int trace = 0;
    int clazz = 1;
    int codegen = 1;

    while ((c = getopt(argc, argv, "tjdrcg")) != -1) {
        if (c == 't') {
            std::cerr <<  "Type Checking mode disabled" << std::endl;
            type = 0;
        }
        if (c == 'j') {
            std::cerr << "Json mode" <<std::endl;
            json = 1;
        }
        if (c ==  'd') {
            std::cerr << "Debugging mode disabled" << std::endl;
            debug = 0;
        }
        if (c == 'r') {
            std::cerr << "Tracing mode" << std::endl;
            trace = 1;
        }
        if (c == 'c') {
            std::cerr << "Class check disabled" << std::endl;
            clazz = 0;
        }
        if (c == 'g') {
            std::cerr << "Code gen disabled" << std::endl;
            codegen = 0;
        }
    }

    for (index = optind; index < argc; ++index) {
        if( !(f = fopen(argv[index], "r"))) {
            perror(argv[index]);
            exit(1);
        }
        Driver driver(f);
        if (trace) driver.debug();
        AST::ASTNode *root = driver.parse();
        if (root != nullptr) {
            if(!report::ok()) {
                exit(8);
            }
            if(debug == 1) {
                std::cout << "root Node is non null" << std::endl;
            }
            //Now we do the semantic checks 
	        if (clazz == 1 && ClassChecker::CheckHierarchy(root) != 0) {
	        	std::cout << "Class Hierarchy invalid terminating..." << std::endl;
		        exit(16);
	        }

            //now for types
            if (type == 1 && TypeChecker::Check(root, debug) != 0) {
                std::cout << "Failed the type checker terminating..." << std::endl;
                exit(32);
            }
            if(json == 1) {
                //Print the json if all goes correctly
                AST::AST_print_context context;
                root->json(std::cout, context);
                std::cout << std::endl;
            }

            CodeGenerator * codeGen = new CodeGenerator(root, debug);

            if (codegen == 1 && codeGen->Generate("code.c") != 0) {
                std::cout << "Failed to generate code" << std::endl;
                exit(128);
            }
        } else {
            std::cout << "No tree produced." << std::endl;
            if(!report::ok()) {
                exit(8);
            }
        }
    }

}
