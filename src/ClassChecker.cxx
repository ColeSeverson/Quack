//Written by Cole Severson Nov 17th

#include "ClassChecker.h"
#include <string>
#include <vector>

namespace ClassChecker {

	struct Clazz {
		std::string name;
		Clazz* super;
	};

	int CheckHierarchy(AST::ASTNode *root) {
		//This is a multi pass method. We will have to pass
		//at least n times where n is the depth of the
		//longest inheritance chain
		struct Clazz Obj = {"obj", NULL};

		return 0;
	}

}
