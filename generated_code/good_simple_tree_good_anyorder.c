#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= Bar =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_Bar_struct;
typedef struct class_Bar_struct* class_Bar;

typedef struct obj_Bar_struct {
	class_Bar clazz;
} * obj_Bar;

struct class_Bar_struct {
	class_Obj super_;
	obj_Bar (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_Bar new_Bar();

struct class_Bar_struct the_class_Bar_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_Bar,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_Bar the_class_Bar = &the_class_Bar_struct;
obj_Bar new_Bar() {
	obj_Bar this = (obj_Bar)malloc(sizeof(struct obj_Bar_struct));
	this->clazz = the_class_Bar;
	/* Method statements */

	return this;
}

/*======================= Foo =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_Foo_struct;
typedef struct class_Foo_struct* class_Foo;

typedef struct obj_Foo_struct {
	class_Foo clazz;
} * obj_Foo;

struct class_Foo_struct {
	class_Obj super_;
	obj_Foo (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_Foo new_Foo();

struct class_Foo_struct the_class_Foo_struct = {
	(class_Obj)&the_class_Bar_struct,
	new_Foo,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_Foo the_class_Foo = &the_class_Foo_struct;
obj_Foo new_Foo() {
	obj_Foo this = (obj_Foo)malloc(sizeof(struct obj_Foo_struct));
	this->clazz = the_class_Foo;
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
