#include "Builtins.h"
#include <stdlib.h>
struct obj_Bar_struct;
typedef struct obj_Bar_struct * obj_Bar;
struct class_Bar_struct;
typedef struct class_Bar_struct * class_Bar;

struct obj_C_struct;
typedef struct obj_C_struct * obj_C;
struct class_C_struct;
typedef struct class_C_struct * class_C;

struct obj_Car_struct;
typedef struct obj_Car_struct * obj_Car;
struct class_Car_struct;
typedef struct class_Car_struct * class_Car;

struct obj_Foo_struct;
typedef struct obj_Foo_struct * obj_Foo;
struct class_Foo_struct;
typedef struct class_Foo_struct * class_Foo;

typedef struct obj_Bar_struct {
	class_Bar clazz;
} * obj_Bar;


struct class_Bar_struct {
	obj_Bar (*constructor) (obj_Boolean );
	obj_String (*STRING) (obj_Obj);
	obj_Nothing (*PRINT) (obj_Obj);
	obj_Boolean (*EQUALS) (obj_Obj, obj_Obj );
	obj_Nothing (*test) (obj_Bar, obj_Int );
};

//Now lets generate the method forward decls so we can delcare the _the_class instance
obj_Bar new_Bar(obj_Boolean c);
obj_Nothing Bar_method_test(obj_Bar this, obj_Int x);
typedef struct obj_C_struct {
	class_C clazz;
} * obj_C;


struct class_C_struct {
	obj_C (*constructor) ();
	obj_String (*STRING) (obj_Obj);
	obj_Nothing (*PRINT) (obj_Obj);
	obj_Boolean (*EQUALS) (obj_Obj, obj_Obj );
};

//Now lets generate the method forward decls so we can delcare the _the_class instance
obj_C new_C();
typedef struct obj_Car_struct {
	class_Car clazz;
} * obj_Car;


struct class_Car_struct {
	obj_Car (*constructor) ();
	obj_Nothing (*test) (obj_Bar, obj_Int );
	obj_String (*STRING) (obj_Obj);
	obj_Nothing (*PRINT) (obj_Obj);
	obj_Boolean (*EQUALS) (obj_Obj, obj_Obj );
};

//Now lets generate the method forward decls so we can delcare the _the_class instance
obj_Car new_Car();
typedef struct obj_Foo_struct {
	class_Foo clazz;
} * obj_Foo;


struct class_Foo_struct {
	obj_Foo (*constructor) (obj_Int , obj_String );
	obj_Nothing (*test) (obj_Bar, obj_Int );
	obj_String (*STRING) (obj_Obj);
	obj_Nothing (*PRINT) (obj_Obj);
	obj_Boolean (*EQUALS) (obj_Obj, obj_Obj );
};

//Now lets generate the method forward decls so we can delcare the _the_class instance
obj_Foo new_Foo(obj_Int a, obj_String b);
struct class_Bar_struct the_class_Bar_struct = {
	new_Bar,
	Obj_method_STRING,
	Obj_method_PRINT,
	Obj_method_EQUALS,
	Bar_method_test
};

//class singleton
 class_Bar the_class_Bar = &the_class_Bar_struct;

obj_Bar new_Bar(obj_Boolean c) {
	obj_Bar this = (obj_Bar)malloc(sizeof(struct obj_Bar_struct));
	this->clazz = the_class_Bar;
	return this;
}

obj_Nothing Bar_method_test(obj_Bar this, obj_Int x) {
}
struct class_C_struct the_class_C_struct = {
	new_C,
	Obj_method_STRING,
	Obj_method_PRINT,
	Obj_method_EQUALS
};

//class singleton
 class_C the_class_C = &the_class_C_struct;

obj_C new_C() {
	obj_C this = (obj_C)malloc(sizeof(struct obj_C_struct));
	this->clazz = the_class_C;
	return this;
}

struct class_Car_struct the_class_Car_struct = {
	new_Car,
	Bar_method_test,
	Obj_method_STRING,
	Obj_method_PRINT,
	Obj_method_EQUALS
};

//class singleton
 class_Car the_class_Car = &the_class_Car_struct;

obj_Car new_Car() {
	obj_Car this = (obj_Car)malloc(sizeof(struct obj_Car_struct));
	this->clazz = the_class_Car;
	return this;
}

struct class_Foo_struct the_class_Foo_struct = {
	new_Foo,
	Bar_method_test,
	Obj_method_STRING,
	Obj_method_PRINT,
	Obj_method_EQUALS
};

//class singleton
 class_Foo the_class_Foo = &the_class_Foo_struct;

obj_Foo new_Foo(obj_Int a, obj_String b) {
	obj_Foo this = (obj_Foo)malloc(sizeof(struct obj_Foo_struct));
	this->clazz = the_class_Foo;
	return this;
}

int main() {
}

