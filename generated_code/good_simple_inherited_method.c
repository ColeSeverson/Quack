#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= A =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_A_struct;
typedef struct class_A_struct* class_A;

typedef struct obj_A_struct {
	class_A clazz;
} * obj_A;

struct class_A_struct {
	class_Obj super_;
	obj_A (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_A);
};

obj_A new_A();
obj_String A_method_STR(obj_A this);

struct class_A_struct the_class_A_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_A,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	A_method_STR
};

class_A the_class_A = &the_class_A_struct;
obj_A new_A() {
	obj_A this = (obj_A)malloc(sizeof(struct obj_A_struct));
	this->clazz = the_class_A;
	/* Method statements */

	return this;
}

obj_String A_method_STR(obj_A this) {
	obj_String __temp_var_0000 = str_literal("This is an A");
	return (obj_String)(__temp_var_0000);
}


obj_Nothing _main() {
	obj_Obj y;
	/* main Method Body */
	obj_A __temp_var_0001 = new_A();
	obj_Obj * __temp_var_0002 = &(y);
	(*__temp_var_0002) = (obj_Obj)(__temp_var_0001);
	obj_Obj __temp_var_0003 = y->clazz->PRINT((obj_Obj)y);
	return none;
}

int main() {
	_main();
}
