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
};

obj_A new_A();

struct class_A_struct the_class_A_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_A,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_A the_class_A = &the_class_A_struct;
obj_A new_A() {
	obj_A this = (obj_A)malloc(sizeof(struct obj_A_struct));
	this->clazz = the_class_A;
	/* Method statements */

	return this;
}

/*======================= B =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_B_struct;
typedef struct class_B_struct* class_B;

typedef struct obj_B_struct {
	class_B clazz;
} * obj_B;

struct class_B_struct {
	class_Obj super_;
	obj_B (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_B new_B();

struct class_B_struct the_class_B_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_B,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_B the_class_B = &the_class_B_struct;
obj_B new_B() {
	obj_B this = (obj_B)malloc(sizeof(struct obj_B_struct));
	this->clazz = the_class_B;
	/* Method statements */

	return this;
}

/*======================= C =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C_struct;
typedef struct class_C_struct* class_C;

typedef struct obj_C_struct {
	class_C clazz;
} * obj_C;

struct class_C_struct {
	class_Obj super_;
	obj_C (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_C new_C();

struct class_C_struct the_class_C_struct = {
	(class_Obj)&the_class_B_struct,
	new_C,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_C the_class_C = &the_class_C_struct;
obj_C new_C() {
	obj_C this = (obj_C)malloc(sizeof(struct obj_C_struct));
	this->clazz = the_class_C;
	/* Method statements */

	return this;
}

/*======================= D =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_D_struct;
typedef struct class_D_struct* class_D;

typedef struct obj_D_struct {
	class_D clazz;
} * obj_D;

struct class_D_struct {
	class_Obj super_;
	obj_D (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_D new_D();

struct class_D_struct the_class_D_struct = {
	(class_Obj)&the_class_A_struct,
	new_D,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_D the_class_D = &the_class_D_struct;
obj_D new_D() {
	obj_D this = (obj_D)malloc(sizeof(struct obj_D_struct));
	this->clazz = the_class_D;
	/* Method statements */

	return this;
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
