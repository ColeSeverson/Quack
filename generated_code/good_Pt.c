#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= Pt =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_Pt_struct;
typedef struct class_Pt_struct* class_Pt;

typedef struct obj_Pt_struct {
	class_Pt clazz;
	obj_Int x;
	obj_Int y;
} * obj_Pt;

struct class_Pt_struct {
	class_Obj super_;
	obj_Pt (*constructor)(obj_Int, obj_Int);
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Pt);
	obj_Pt (*PLUS)(obj_Pt, obj_Pt);
	obj_Int (*_get_x)(obj_Pt);
	obj_Int (*_get_y)(obj_Pt);
	obj_Nothing (*translate)(obj_Pt, obj_Int, obj_Int);
};

obj_Pt new_Pt(obj_Int x, obj_Int y);
obj_Pt Pt_method_PLUS(obj_Pt this, obj_Pt other);
obj_String Pt_method_STR(obj_Pt this);
obj_Int Pt_method__get_x(obj_Pt this);
obj_Int Pt_method__get_y(obj_Pt this);
obj_Nothing Pt_method_translate(obj_Pt this, obj_Int dx, obj_Int dy);

struct class_Pt_struct the_class_Pt_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_Pt,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Pt_method_STR,
	Pt_method_PLUS,
	Pt_method__get_x,
	Pt_method__get_y,
	Pt_method_translate
};

class_Pt the_class_Pt = &the_class_Pt_struct;
obj_Pt new_Pt(obj_Int x, obj_Int y) {
	obj_Pt this = (obj_Pt)malloc(sizeof(struct obj_Pt_struct));
	this->clazz = the_class_Pt;	obj_Int z;

	/* Method statements */
	obj_Int * __temp_var_0000 = &(this->x);
	(*__temp_var_0000) = (obj_Int)(x);
	obj_Int * __temp_var_0001 = &(this->y);
	(*__temp_var_0001) = (obj_Int)(y);
	obj_Int __temp_var_0002 = this->x;
	obj_Int __temp_var_0003 = int_literal(4);
	obj_Boolean __temp_var_0004 = __temp_var_0002->clazz->MORE((obj_Int)__temp_var_0002, (obj_Int)__temp_var_0003);
	if(lit_true == __temp_var_0004) { goto if0000; }
	goto else0001;
	/* True Part If */
	if0000: ; /* Null statement */
			obj_Int __temp_var_0005 = int_literal(5);
			z = (obj_Int)(__temp_var_0005);
	goto end_if0002;
	/* False Part If */
	else0001: ; /* Null statement */
	/* End If */
	end_if0002: ; /* Null statement */

	return this;
}

obj_Pt Pt_method_PLUS(obj_Pt this, obj_Pt other) {
	obj_Int __temp_var_0006 = this->x;
	obj_Int __temp_var_0007 = other->x;
	obj_Int __temp_var_0008 = __temp_var_0006->clazz->PLUS((obj_Int)__temp_var_0006, (obj_Int)__temp_var_0007);
	obj_Int __temp_var_0009 = this->y;
	obj_Int __temp_var_0010 = other->y;
	obj_Int __temp_var_0011 = __temp_var_0009->clazz->PLUS((obj_Int)__temp_var_0009, (obj_Int)__temp_var_0010);
	obj_Pt __temp_var_0012 = new_Pt((obj_Int)__temp_var_0008, (obj_Int)__temp_var_0011);
	return (obj_Pt)(__temp_var_0012);
}

obj_String Pt_method_STR(obj_Pt this) {
	obj_String __temp_var_0013 = str_literal("(");
	obj_Int __temp_var_0014 = this->x;
	obj_String __temp_var_0015 = __temp_var_0014->clazz->STR((obj_Int)__temp_var_0014);
	obj_String __temp_var_0016 = __temp_var_0013->clazz->PLUS((obj_String)__temp_var_0013, (obj_String)__temp_var_0015);
	obj_String __temp_var_0017 = str_literal(", ");
	obj_String __temp_var_0018 = __temp_var_0016->clazz->PLUS((obj_String)__temp_var_0016, (obj_String)__temp_var_0017);
	obj_Int __temp_var_0019 = this->y;
	obj_String __temp_var_0020 = __temp_var_0019->clazz->STR((obj_Int)__temp_var_0019);
	obj_String __temp_var_0021 = __temp_var_0018->clazz->PLUS((obj_String)__temp_var_0018, (obj_String)__temp_var_0020);
	obj_String __temp_var_0022 = str_literal(")");
	obj_String __temp_var_0023 = __temp_var_0021->clazz->PLUS((obj_String)__temp_var_0021, (obj_String)__temp_var_0022);
	return (obj_String)(__temp_var_0023);
}

obj_Int Pt_method__get_x(obj_Pt this) {
	obj_Int __temp_var_0024 = this->x;
	return (obj_Int)(__temp_var_0024);
}

obj_Int Pt_method__get_y(obj_Pt this) {
	obj_Int __temp_var_0025 = this->y;
	return (obj_Int)(__temp_var_0025);
}

obj_Nothing Pt_method_translate(obj_Pt this, obj_Int dx, obj_Int dy) {
	obj_Int __temp_var_0026 = this->x;
	obj_Int __temp_var_0027 = __temp_var_0026->clazz->PLUS((obj_Int)__temp_var_0026, (obj_Int)dx);
	obj_Int * __temp_var_0028 = &(this->x);
	(*__temp_var_0028) = (obj_Int)(__temp_var_0027);
	obj_Int __temp_var_0029 = this->y;
	obj_Int __temp_var_0030 = __temp_var_0029->clazz->PLUS((obj_Int)__temp_var_0029, (obj_Int)dy);
	obj_Int * __temp_var_0031 = &(this->y);
	(*__temp_var_0031) = (obj_Int)(__temp_var_0030);
	return (obj_Nothing)(none);
}


obj_Nothing _main() {
	/* main Method Body */
	obj_Int __temp_var_0032 = int_literal(13);
	obj_Int __temp_var_0033 = int_literal(42);
	obj_Pt __temp_var_0034 = new_Pt((obj_Int)__temp_var_0032, (obj_Int)__temp_var_0033);
	obj_Obj __temp_var_0035 = __temp_var_0034->clazz->PRINT((obj_Obj)__temp_var_0034);
	return none;
}

int main() {
	_main();
}
