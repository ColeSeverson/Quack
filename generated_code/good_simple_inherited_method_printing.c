#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= C1 =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C1_struct;
typedef struct class_C1_struct* class_C1;

typedef struct obj_C1_struct {
	class_C1 clazz;
} * obj_C1;

struct class_C1_struct {
	class_Obj super_;
	obj_C1 (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_C1);
};

obj_C1 new_C1();
obj_String C1_method_STR(obj_C1 this);

struct class_C1_struct the_class_C1_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	C1_method_STR
};

class_C1 the_class_C1 = &the_class_C1_struct;
obj_C1 new_C1() {
	obj_C1 this = (obj_C1)malloc(sizeof(struct obj_C1_struct));
	this->clazz = the_class_C1;
	/* Method statements */

	return this;
}

obj_String C1_method_STR(obj_C1 this) {
	obj_String __temp_var_0000 = str_literal("This is a C1.\n");
	return (obj_String)(__temp_var_0000);
}

/*======================= C2 =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C2_struct;
typedef struct class_C2_struct* class_C2;

typedef struct obj_C2_struct {
	class_C2 clazz;
} * obj_C2;

struct class_C2_struct {
	class_Obj super_;
	obj_C2 (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_C2);
};

obj_C2 new_C2();
obj_String C2_method_STR(obj_C2 this);

struct class_C2_struct the_class_C2_struct = {
	(class_Obj)&the_class_C1_struct,
	new_C2,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	C2_method_STR
};

class_C2 the_class_C2 = &the_class_C2_struct;
obj_C2 new_C2() {
	obj_C2 this = (obj_C2)malloc(sizeof(struct obj_C2_struct));
	this->clazz = the_class_C2;
	/* Method statements */

	return this;
}

obj_String C2_method_STR(obj_C2 this) {
	obj_String __temp_var_0001 = str_literal("This is a C2.\n");
	return (obj_String)(__temp_var_0001);
}


obj_Nothing _main() {
	obj_Obj my_obj;
	/* main Method Body */
	obj_C1 __temp_var_0002 = new_C1();
	obj_Obj * __temp_var_0003 = &(my_obj);
	(*__temp_var_0003) = (obj_Obj)(__temp_var_0002);
	obj_Obj __temp_var_0004 = my_obj->clazz->PRINT((obj_Obj)my_obj);
	obj_C2 __temp_var_0005 = new_C2();
	my_obj = (obj_Obj)(__temp_var_0005);
	obj_Obj __temp_var_0006 = my_obj->clazz->PRINT((obj_Obj)my_obj);
	return none;
}

int main() {
	_main();
}
