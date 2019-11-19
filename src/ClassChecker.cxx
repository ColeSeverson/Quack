//Written by Cole Severson Nov 17th

#include "ClassChecker.h"
#include "Messages.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

namespace ClassChecker {

	struct Clazz {
		std::string name;
		std::string super;
		bool rooted;
		std::vector<struct Clazz *> * children;
	};
	
	std::string constructString(std::vector<struct Clazz *> * children) {
		std::string toRet = "";
		for(auto kid : *children) {
			toRet + " " + kid->name;
		}
		return toRet;
	}
	void printTree(struct Clazz * node, int indent) {
		std::string indentString(indent, ' ');
		std::cout << indentString << node->name << ": " << constructString(node->children) << std::endl;
		for(auto child : *node->children) {
			printTree(child, indent + 4);
		}
	}
	//recursive method to 'root' tree
	void isRooted(struct Clazz * root) {
		for(auto child : *(root->children)) {
			child->rooted = root->rooted;
			isRooted(child);
		}
	}
	int CheckHierarchy(AST::ASTNode *root_) {
		//This is a multi pass method. We will have to pass
		//at least n times where n is the depth of the
		//longest inheritance chain
		//std::cout << "Entering Hierarchy Method" << std::endl;
		AST::Program * root = dynamic_cast<AST::Program *>(root_);
		//Here we will store information about classes we have seen
		std::map<std::string, struct Clazz *> seenClasses;
		//add the builtins
		std::vector<struct Clazz *> *intChildren = new std::vector<struct Clazz *>();
		struct Clazz Int = {"Int", "Obj", true, intChildren};
		std::vector<struct Clazz *> *stringChildren = new std::vector<struct Clazz *>();
		struct Clazz String = {"String", "Obj", true, stringChildren};
		std::vector<struct Clazz *> *boolChildren = new std::vector<struct Clazz *>();
		struct Clazz Bool = {"Bool", "Obj", true, boolChildren};
		
		//Create a Clazz to represent Obj
		std::vector<struct Clazz *> * objChildren = new std::vector<struct Clazz *>();
		struct Clazz Obj = {"Obj", "Obj", true, objChildren};
		seenClasses.insert({"Obj", &Obj});
		seenClasses.insert({"Int", &Int});
		seenClasses.insert({"String", &String});
		seenClasses.insert({"Bool", &Bool});


		//std::cout << "Created the obj struct" << std::endl; 
		AST::Classes astclasses = root->classes_;

		//std::cout << "Retrieved the Classes" << std::endl;
		std::vector<AST::Class *> classes = astclasses.getElements();

		//std::cout << "Created the class vector" << std::endl;
		for(auto clas : classes) {
			//retrieve info we need to check hierarchy
			//std::cout << "Class: " << clas->getName()->getText() << " Super: " << clas->getSuper()->getText() << std::endl;
			std::string name = clas->getName()->getText();
			std::string super = clas->getSuper()->getText();

			//check the name to see if it is alreadt defined
			std::map<std::string, struct Clazz *>::iterator it = seenClasses.find(name);
			if(it != seenClasses.end()) {
				report::error("Class " + name + " already defined... redifinition");
				exit(16);
			}

			//Create the Clazz element to represent this AST::Class
			struct Clazz * toAdd = new struct Clazz();
            toAdd->name = name;
			toAdd->super = super;
			std::vector<struct Clazz *> * vect = new std::vector<struct Clazz *>();
			toAdd->children = vect;
			toAdd->rooted = false;
			seenClasses.insert({name, toAdd});
		}

		//now that the map contains all of the nodes we can run through it and create the tree
		for(const auto& pair : seenClasses) {
			//std::cout << "seenCLasses Clazz: " << pair.second->name << " extends: " << pair.second->super << std::endl;
			struct Clazz * current = pair.second;
			
			//We don't need to process the root Obj
			if(current->name.compare("Obj") == 0)
				continue;

			std::map<std::string, struct Clazz *>::iterator it = seenClasses.find(current->super);
			if(it != seenClasses.end()) {
				struct Clazz * superClazz = it->second;
				superClazz->children->push_back(current);
				current->rooted = superClazz->rooted;
			} else {
				//This is a no superclass error!
				report::error("No class of name " + current->super + " exists. Class " + current->name + " tries to extend it...");
				exit(16);
			}
		}

		//We have to run through the program's classes sequence to initially build
		//We will run down from the obj root
		isRooted(&Obj);
		bool flag = false;
		for(const auto& pair : seenClasses) {
			if(pair.second->rooted == false) {
				report::error("Class " + pair.second->name + " is not rooted at Obj");
				flag = true;
			}
		}
		if(flag == true) {
			exit(16);
		}
		printTree(&Obj, 0);
		return 0;
	}
}
