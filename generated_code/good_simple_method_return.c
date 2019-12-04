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
	obj_String (*STR)(obj_Obj);
	obj_Int (*foo)(obj_A);
};

obj_A new_A();
obj_Int A_method_foo(obj_A this);

struct class_A_struct the_class_A_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_A,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	A_method_foo
};

class_A the_class_A = &the_class_A_struct;
obj_A new_A() {
	obj_A this = (obj_A)malloc(sizeof(struct obj_A_struct));
	this->clazz = the_class_A;
	/* Method statements */

	return this;
}

obj_Int A_method_foo(obj_A this) {
	obj_Int __temp_var_0000 = int_literal(42);
	return (obj_Int)(__temp_var_0000);
}


obj_Nothing _main() {
	obj_A x;
	/* main Method Body */
	obj_A __temp_var_0001 = new_A();
	x = (obj_A)(__temp_var_0001);
	obj_Int __temp_var_0002 = x->clazz->foo((obj_A)x);
	obj_Obj __temp_var_0003 = __temp_var_0002->clazz->PRINT((obj_Obj)__temp_var_0002);
	return none;
}

int main() {
	_main();
}
