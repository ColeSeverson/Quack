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
	obj_String (*STR)(obj_Obj);
	obj_C1 (*foo)(obj_C1);
};

obj_C1 new_C1();
obj_C1 C1_method_foo(obj_C1 this);

struct class_C1_struct the_class_C1_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C1_method_foo
};

class_C1 the_class_C1 = &the_class_C1_struct;
obj_C1 new_C1() {
	obj_C1 this = (obj_C1)malloc(sizeof(struct obj_C1_struct));
	this->clazz = the_class_C1;
	/* Method statements */

	return this;
}

obj_C1 C1_method_foo(obj_C1 this) {
	obj_String __temp_var_0000 = str_literal("Loop Run\n");
	obj_Obj __temp_var_0001 = __temp_var_0000->clazz->PRINT((obj_Obj)__temp_var_0000);
	obj_C1 __temp_var_0002 = new_C1();
	return (obj_C1)(__temp_var_0002);
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
	obj_String (*STR)(obj_Obj);
	obj_C1 (*foo)(obj_C2);
};

obj_C2 new_C2();
obj_C1 C2_method_foo(obj_C2 this);

struct class_C2_struct the_class_C2_struct = {
	(class_Obj)&the_class_C1_struct,
	new_C2,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C2_method_foo
};

class_C2 the_class_C2 = &the_class_C2_struct;
obj_C2 new_C2() {
	obj_C2 this = (obj_C2)malloc(sizeof(struct obj_C2_struct));
	this->clazz = the_class_C2;
	/* Method statements */

	return this;
}

obj_C1 C2_method_foo(obj_C2 this) {
	obj_C1 __temp_var_0003 = new_C1();
	return (obj_C1)(__temp_var_0003);
}

/*======================= C3 =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C3_struct;
typedef struct class_C3_struct* class_C3;

typedef struct obj_C3_struct {
	class_C3 clazz;
} * obj_C3;

struct class_C3_struct {
	class_Obj super_;
	obj_C3 (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_C2 (*foo)(obj_C3);
};

obj_C3 new_C3();
obj_C2 C3_method_foo(obj_C3 this);

struct class_C3_struct the_class_C3_struct = {
	(class_Obj)&the_class_C2_struct,
	new_C3,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C3_method_foo
};

class_C3 the_class_C3 = &the_class_C3_struct;
obj_C3 new_C3() {
	obj_C3 this = (obj_C3)malloc(sizeof(struct obj_C3_struct));
	this->clazz = the_class_C3;
	/* Method statements */

	return this;
}

obj_C2 C3_method_foo(obj_C3 this) {
	obj_C2 __temp_var_0004 = new_C2();
	return (obj_C2)(__temp_var_0004);
}

/*======================= C4 =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C4_struct;
typedef struct class_C4_struct* class_C4;

typedef struct obj_C4_struct {
	class_C4 clazz;
} * obj_C4;

struct class_C4_struct {
	class_Obj super_;
	obj_C4 (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_C3 (*foo)(obj_C4);
};

obj_C4 new_C4();
obj_C3 C4_method_foo(obj_C4 this);

struct class_C4_struct the_class_C4_struct = {
	(class_Obj)&the_class_C3_struct,
	new_C4,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C4_method_foo
};

class_C4 the_class_C4 = &the_class_C4_struct;
obj_C4 new_C4() {
	obj_C4 this = (obj_C4)malloc(sizeof(struct obj_C4_struct));
	this->clazz = the_class_C4;
	/* Method statements */

	return this;
}

obj_C3 C4_method_foo(obj_C4 this) {
	obj_C3 __temp_var_0005 = new_C3();
	return (obj_C3)(__temp_var_0005);
}


obj_Nothing _main() {
	obj_C1 x;
	obj_Int y;
	/* main Method Body */
	obj_C4 __temp_var_0006 = new_C4();
	x = (obj_C1)(__temp_var_0006);
	obj_Int __temp_var_0007 = int_literal(1);
	y = (obj_Int)(__temp_var_0007);
	/* WHILE Loop Start */
	goto test_cond0000;
	loop_again0001: ; /* Null statement */
			obj_C1 __temp_var_0008 = x->clazz->foo((obj_C1)x);
			x = (obj_C1)(__temp_var_0008);
			obj_Int __temp_var_0009 = int_literal(1);
			obj_Int __temp_var_0010 = y->clazz->PLUS((obj_Int)y, (obj_Int)__temp_var_0009);
			y = (obj_Int)(__temp_var_0010);
	test_cond0000: ; /* Null statement */
	/* Generate AND */
		goto halfway0003;	halfway0003: ; /* Null statement */
		obj_Int __temp_var_0011 = int_literal(10);
		obj_Boolean __temp_var_0012 = y->clazz->LESS((obj_Int)y, (obj_Int)__temp_var_0011);
		if(lit_true == __temp_var_0012) { goto loop_again0001; }
		goto end_while0002;
	end_while0002: ; /* Null statement */
	/* END WHILE Loop */
	return none;
}

int main() {
	_main();
}
