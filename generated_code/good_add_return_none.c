#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= AddReturnNone =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_AddReturnNone_struct;
typedef struct class_AddReturnNone_struct* class_AddReturnNone;

typedef struct obj_AddReturnNone_struct {
	class_AddReturnNone clazz;
} * obj_AddReturnNone;

struct class_AddReturnNone_struct {
	class_Obj super_;
	obj_AddReturnNone (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_Nothing (*dummy)(obj_AddReturnNone);
	obj_Obj (*dummy2)(obj_AddReturnNone);
};

obj_AddReturnNone new_AddReturnNone();
obj_Nothing AddReturnNone_method_dummy(obj_AddReturnNone this);
obj_Obj AddReturnNone_method_dummy2(obj_AddReturnNone this);

struct class_AddReturnNone_struct the_class_AddReturnNone_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_AddReturnNone,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	AddReturnNone_method_dummy,
	AddReturnNone_method_dummy2
};

class_AddReturnNone the_class_AddReturnNone = &the_class_AddReturnNone_struct;
obj_AddReturnNone new_AddReturnNone() {
	obj_AddReturnNone this = (obj_AddReturnNone)malloc(sizeof(struct obj_AddReturnNone_struct));
	this->clazz = the_class_AddReturnNone;
	/* Method statements */

	return this;
}

obj_Nothing AddReturnNone_method_dummy(obj_AddReturnNone this) {
	return (obj_Nothing)(none);
}

obj_Obj AddReturnNone_method_dummy2(obj_AddReturnNone this) {
	return (obj_Obj)(none);
}


obj_Nothing _main() {
	obj_AddReturnNone x;
	/* main Method Body */
	obj_AddReturnNone __temp_var_0000 = new_AddReturnNone();
	x = (obj_AddReturnNone)(__temp_var_0000);
	obj_Nothing __temp_var_0001 = x->clazz->dummy((obj_AddReturnNone)x);
	obj_Obj __temp_var_0002 = __temp_var_0001->clazz->PRINT((obj_Obj)__temp_var_0001);
	obj_String __temp_var_0003 = str_literal("\n");
	obj_Obj __temp_var_0004 = __temp_var_0003->clazz->PRINT((obj_Obj)__temp_var_0003);
	obj_Obj __temp_var_0005 = x->clazz->dummy2((obj_AddReturnNone)x);
	obj_Obj __temp_var_0006 = __temp_var_0005->clazz->PRINT((obj_Obj)__temp_var_0005);
	return none;
}

int main() {
	_main();
}
