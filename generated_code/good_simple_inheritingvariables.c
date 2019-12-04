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
	obj_Int x;
} * obj_C1;

struct class_C1_struct {
	class_Obj super_;
	obj_C1 (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_C1 new_C1();

struct class_C1_struct the_class_C1_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_C1 the_class_C1 = &the_class_C1_struct;
obj_C1 new_C1() {
	obj_C1 this = (obj_C1)malloc(sizeof(struct obj_C1_struct));
	this->clazz = the_class_C1;
	/* Method statements */
	obj_Int __temp_var_0000 = int_literal(5);
	obj_Int * __temp_var_0001 = &(this->x);
	(*__temp_var_0001) = (obj_Int)(__temp_var_0000);

	return this;
}

/*======================= C2 =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C2_struct;
typedef struct class_C2_struct* class_C2;

typedef struct obj_C2_struct {
	class_C2 clazz;
	obj_Int x;
} * obj_C2;

struct class_C2_struct {
	class_Obj super_;
	obj_C2 (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_C2 new_C2();

struct class_C2_struct the_class_C2_struct = {
	(class_Obj)&the_class_C1_struct,
	new_C2,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_C2 the_class_C2 = &the_class_C2_struct;
obj_C2 new_C2() {
	obj_C2 this = (obj_C2)malloc(sizeof(struct obj_C2_struct));
	this->clazz = the_class_C2;
	/* Method statements */
	obj_Int __temp_var_0002 = int_literal(8);
	obj_Int * __temp_var_0003 = &(this->x);
	(*__temp_var_0003) = (obj_Int)(__temp_var_0002);

	return this;
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
