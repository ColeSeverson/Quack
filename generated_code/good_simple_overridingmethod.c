#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= P =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_P_struct;
typedef struct class_P_struct* class_P;

typedef struct obj_P_struct {
	class_P clazz;
} * obj_P;

struct class_P_struct {
	class_Obj super_;
	obj_P (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_Int (*s)(obj_P, obj_Int);
};

obj_P new_P();
obj_Int P_method_s(obj_P this, obj_Int x);

struct class_P_struct the_class_P_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_P,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	P_method_s
};

class_P the_class_P = &the_class_P_struct;
obj_P new_P() {
	obj_P this = (obj_P)malloc(sizeof(struct obj_P_struct));
	this->clazz = the_class_P;
	/* Method statements */

	return this;
}

obj_Int P_method_s(obj_P this, obj_Int x) {
	return (obj_Int)(x);
}

/*======================= X =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_X_struct;
typedef struct class_X_struct* class_X;

typedef struct obj_X_struct {
	class_X clazz;
} * obj_X;

struct class_X_struct {
	class_Obj super_;
	obj_X (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_Int (*s)(obj_X, obj_Int);
};

obj_X new_X();
obj_Int X_method_s(obj_X this, obj_Int x);

struct class_X_struct the_class_X_struct = {
	(class_Obj)&the_class_P_struct,
	new_X,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	X_method_s
};

class_X the_class_X = &the_class_X_struct;
obj_X new_X() {
	obj_X this = (obj_X)malloc(sizeof(struct obj_X_struct));
	this->clazz = the_class_X;
	/* Method statements */

	return this;
}

obj_Int X_method_s(obj_X this, obj_Int x) {
	obj_Int __temp_var_0000 = int_literal(1);
	obj_Int __temp_var_0001 = x->clazz->PLUS((obj_Int)x, (obj_Int)__temp_var_0000);
	return (obj_Int)(__temp_var_0001);
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
