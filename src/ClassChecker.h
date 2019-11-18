//Written by Cole Severson November 17th
//This class will check a quack program's hierarchy given the AST representation
#ifndef CLASSCHECKER
#define CLASSCHECKER

//Include ASTNode so that we have reference to the type
#include "ASTNode.h"

namespace ClassChecker {
	int CheckHierarchy(AST::ASTNode *root);	

}

#endif
