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
	obj_Int w;
	obj_Int x;
	obj_Int y;
	obj_Int z;
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
	this->clazz = the_class_Pt;
	/* Method statements */
	obj_Int * __temp_var_0000 = &(this->x);
	(*__temp_var_0000) = (obj_Int)(x);
	obj_Int * __temp_var_0001 = &(this->y);
	(*__temp_var_0001) = (obj_Int)(y);
	obj_Int __temp_var_0002 = int_literal(5);
	obj_Int __temp_var_0003 = int_literal(2);
	obj_Int __temp_var_0004 = __temp_var_0002->clazz->TIMES((obj_Int)__temp_var_0002, (obj_Int)__temp_var_0003);
	obj_Int __temp_var_0005 = int_literal(7);
	obj_Int __temp_var_0006 = int_literal(2);
	obj_Int __temp_var_0007 = __temp_var_0005->clazz->DIVIDE((obj_Int)__temp_var_0005, (obj_Int)__temp_var_0006);
	obj_Int __temp_var_0008 = __temp_var_0004->clazz->PLUS((obj_Int)__temp_var_0004, (obj_Int)__temp_var_0007);
	obj_Int * __temp_var_0009 = &(this->w);
	(*__temp_var_0009) = (obj_Int)(__temp_var_0008);
	obj_Int __temp_var_0010 = this->x;
	obj_Int __temp_var_0011 = this->y;
	obj_Int __temp_var_0012 = __temp_var_0010->clazz->PLUS((obj_Int)__temp_var_0010, (obj_Int)__temp_var_0011);
	obj_Int * __temp_var_0013 = &(this->z);
	(*__temp_var_0013) = (obj_Int)(__temp_var_0012);

	return this;
}

obj_Pt Pt_method_PLUS(obj_Pt this, obj_Pt other) {
	obj_Int __temp_var_0014 = this->x;
	obj_Int __temp_var_0015 = other->x;
	obj_Int __temp_var_0016 = __temp_var_0014->clazz->PLUS((obj_Int)__temp_var_0014, (obj_Int)__temp_var_0015);
	obj_Int __temp_var_0017 = this->y;
	obj_Int __temp_var_0018 = other->y;
	obj_Int __temp_var_0019 = __temp_var_0017->clazz->PLUS((obj_Int)__temp_var_0017, (obj_Int)__temp_var_0018);
	obj_Pt __temp_var_0020 = new_Pt((obj_Int)__temp_var_0016, (obj_Int)__temp_var_0019);
	return (obj_Pt)(__temp_var_0020);
}

obj_String Pt_method_STR(obj_Pt this) {
	obj_String __temp_var_0021 = str_literal("x = ");
	obj_Int __temp_var_0022 = this->x;
	obj_String __temp_var_0023 = __temp_var_0022->clazz->STR((obj_Int)__temp_var_0022);
	obj_String __temp_var_0024 = __temp_var_0021->clazz->PLUS((obj_String)__temp_var_0021, (obj_String)__temp_var_0023);
	obj_String __temp_var_0025 = str_literal(", y = ");
	obj_String __temp_var_0026 = __temp_var_0024->clazz->PLUS((obj_String)__temp_var_0024, (obj_String)__temp_var_0025);
	obj_Int __temp_var_0027 = this->y;
	obj_String __temp_var_0028 = __temp_var_0027->clazz->STR((obj_Int)__temp_var_0027);
	obj_String __temp_var_0029 = __temp_var_0026->clazz->PLUS((obj_String)__temp_var_0026, (obj_String)__temp_var_0028);
	obj_String __temp_var_0030 = str_literal(", this.w = ");
	obj_String __temp_var_0031 = __temp_var_0029->clazz->PLUS((obj_String)__temp_var_0029, (obj_String)__temp_var_0030);
	obj_Int __temp_var_0032 = this->w;
	obj_String __temp_var_0033 = __temp_var_0032->clazz->STR((obj_Int)__temp_var_0032);
	obj_String __temp_var_0034 = __temp_var_0031->clazz->PLUS((obj_String)__temp_var_0031, (obj_String)__temp_var_0033);
	obj_String __temp_var_0035 = str_literal(", this.z = ");
	obj_String __temp_var_0036 = __temp_var_0034->clazz->PLUS((obj_String)__temp_var_0034, (obj_String)__temp_var_0035);
	obj_Int __temp_var_0037 = this->z;
	obj_String __temp_var_0038 = __temp_var_0037->clazz->STR((obj_Int)__temp_var_0037);
	obj_String __temp_var_0039 = __temp_var_0036->clazz->PLUS((obj_String)__temp_var_0036, (obj_String)__temp_var_0038);
	return (obj_String)(__temp_var_0039);
}

obj_Int Pt_method__get_x(obj_Pt this) {
	obj_Int __temp_var_0040 = this->x;
	return (obj_Int)(__temp_var_0040);
}

obj_Int Pt_method__get_y(obj_Pt this) {
	obj_Int __temp_var_0041 = this->y;
	return (obj_Int)(__temp_var_0041);
}

obj_Nothing Pt_method_translate(obj_Pt this, obj_Int dx, obj_Int dy) {
	obj_Int __temp_var_0042 = this->x;
	obj_Int __temp_var_0043 = __temp_var_0042->clazz->PLUS((obj_Int)__temp_var_0042, (obj_Int)dx);
	obj_Int * __temp_var_0044 = &(this->x);
	(*__temp_var_0044) = (obj_Int)(__temp_var_0043);
	obj_Int __temp_var_0045 = this->y;
	obj_Int __temp_var_0046 = __temp_var_0045->clazz->PLUS((obj_Int)__temp_var_0045, (obj_Int)dy);
	obj_Int * __temp_var_0047 = &(this->y);
	(*__temp_var_0047) = (obj_Int)(__temp_var_0046);
	return (obj_Nothing)(none);
}


obj_Nothing _main() {
	/* main Method Body */
	obj_Int __temp_var_0048 = int_literal(13);
	obj_Int __temp_var_0049 = int_literal(42);
	obj_Pt __temp_var_0050 = new_Pt((obj_Int)__temp_var_0048, (obj_Int)__temp_var_0049);
	obj_Obj __temp_var_0051 = __temp_var_0050->clazz->PRINT((obj_Obj)__temp_var_0050);
	return none;
}

int main() {
	_main();
}
