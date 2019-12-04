#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= Point =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_Point_struct;
typedef struct class_Point_struct* class_Point;

typedef struct obj_Point_struct {
	class_Point clazz;
	obj_Int x;
	obj_Int y;
} * obj_Point;

struct class_Point_struct {
	class_Obj super_;
	obj_Point (*constructor)(obj_Int, obj_Int);
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Point);
	obj_Obj (*type_case)(obj_Point, obj_Obj);
};

obj_Point new_Point(obj_Int x, obj_Int y);
obj_String Point_method_STR(obj_Point this);
obj_Obj Point_method_type_case(obj_Point this, obj_Obj other);

struct class_Point_struct the_class_Point_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_Point,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Point_method_STR,
	Point_method_type_case
};

class_Point the_class_Point = &the_class_Point_struct;
obj_Point new_Point(obj_Int x, obj_Int y) {
	obj_Point this = (obj_Point)malloc(sizeof(struct obj_Point_struct));
	this->clazz = the_class_Point;
	/* Method statements */
	obj_Int * __temp_var_0000 = &(this->x);
	(*__temp_var_0000) = (obj_Int)(x);
	obj_Int * __temp_var_0001 = &(this->y);
	(*__temp_var_0001) = (obj_Int)(y);

	return this;
}

obj_String Point_method_STR(obj_Point this) {
	obj_String __temp_var_0002 = str_literal("(");
	obj_Int __temp_var_0003 = this->x;
	obj_String __temp_var_0004 = __temp_var_0003->clazz->STR((obj_Int)__temp_var_0003);
	obj_String __temp_var_0005 = __temp_var_0002->clazz->PLUS((obj_String)__temp_var_0002, (obj_String)__temp_var_0004);
	obj_String __temp_var_0006 = str_literal(", ");
	obj_String __temp_var_0007 = __temp_var_0005->clazz->PLUS((obj_String)__temp_var_0005, (obj_String)__temp_var_0006);
	obj_Int __temp_var_0008 = this->y;
	obj_String __temp_var_0009 = __temp_var_0008->clazz->STR((obj_Int)__temp_var_0008);
	obj_String __temp_var_0010 = __temp_var_0007->clazz->PLUS((obj_String)__temp_var_0007, (obj_String)__temp_var_0009);
	obj_String __temp_var_0011 = str_literal(")");
	obj_String __temp_var_0012 = __temp_var_0010->clazz->PLUS((obj_String)__temp_var_0010, (obj_String)__temp_var_0011);
	obj_String __temp_var_0013 = str_literal("\n");
	obj_String __temp_var_0014 = __temp_var_0012->clazz->PLUS((obj_String)__temp_var_0012, (obj_String)__temp_var_0013);
	return (obj_String)(__temp_var_0014);
}

obj_Obj Point_method_type_case(obj_Point this, obj_Obj other) {
	obj_Point pt;
	obj_Obj thing;
	obj_Nothing y;
	obj_Int z;
	/* Typecase START */
	/* Typecase Type - Point */
	typecase_Point_0001: ; /* Null statement */
	if(!is_subtype(other->clazz, (class_Obj)(&the_class_Point_struct))) { goto typecase_Nothing_0002; }
		pt = (obj_Point)(other);
		obj_String __temp_var_0015 = str_literal("Point received.\n");
		obj_Obj __temp_var_0016 = __temp_var_0015->clazz->PRINT((obj_Obj)__temp_var_0015);
		obj_Obj __temp_var_0017 = pt->clazz->PRINT((obj_Obj)pt);
		obj_Boolean __temp_var_0018 = lit_false;
		/* and Left Condition */
			obj_Int __temp_var_0019 = this->x;
			obj_Int __temp_var_0020 = pt->x;
			obj_Boolean __temp_var_0021 = __temp_var_0019->clazz->EQUALS((obj_Int)__temp_var_0019, (obj_Obj)__temp_var_0020);
			if(lit_true == __temp_var_0021) { goto and_HALFWAY0005; }
			goto and_END0007;
		and_HALFWAY0005: ; /* Null statement */		/* and Right Condition */
			obj_Int __temp_var_0022 = this->y;
			obj_Int __temp_var_0023 = pt->y;
			obj_Boolean __temp_var_0024 = __temp_var_0022->clazz->EQUALS((obj_Int)__temp_var_0022, (obj_Obj)__temp_var_0023);
			if(lit_true == __temp_var_0024) { goto and_TRUE0006; }
			goto and_END0007;
		/* Boolean Get True */
		and_TRUE0006: ; /* Null statement */
		__temp_var_0018 = lit_true;
		and_END0007: ; /* Null statement */
		/* and End */
		return (obj_Obj)(__temp_var_0018);
	goto end_typecase0000;
	/* Typecase Type - Nothing */
	typecase_Nothing_0002: ; /* Null statement */
	if(!is_subtype(other->clazz, (class_Obj)(&the_class_Nothing_struct))) { goto typecase_Int_0003; }
		y = (obj_Nothing)(other);
		obj_String __temp_var_0025 = str_literal("Nothing received.\n");
		obj_Obj __temp_var_0026 = __temp_var_0025->clazz->PRINT((obj_Obj)__temp_var_0025);
		obj_Obj __temp_var_0027 = y->clazz->PRINT((obj_Obj)y);
		obj_String __temp_var_0028 = str_literal("\n");
		obj_Obj __temp_var_0029 = __temp_var_0028->clazz->PRINT((obj_Obj)__temp_var_0028);
		return (obj_Obj)(lit_false);
	goto end_typecase0000;
	/* Typecase Type - Int */
	typecase_Int_0003: ; /* Null statement */
	if(!is_subtype(other->clazz, (class_Obj)(&the_class_Int_struct))) { goto typecase_Obj_0004; }
		z = (obj_Int)(other);
		obj_String __temp_var_0030 = str_literal("Int received.\n");
		obj_Obj __temp_var_0031 = __temp_var_0030->clazz->PRINT((obj_Obj)__temp_var_0030);
		obj_Obj __temp_var_0032 = z->clazz->PRINT((obj_Obj)z);
		obj_String __temp_var_0033 = str_literal("\n");
		obj_Obj __temp_var_0034 = __temp_var_0033->clazz->PRINT((obj_Obj)__temp_var_0033);
	goto end_typecase0000;
	/* Typecase Type - Obj */
	typecase_Obj_0004: ; /* Null statement */
	if(!is_subtype(other->clazz, (class_Obj)(&the_class_Obj_struct))) { goto end_typecase0000; }
		thing = (obj_Obj)(other);
		obj_String __temp_var_0035 = str_literal("Object received.\n");
		obj_Obj __temp_var_0036 = __temp_var_0035->clazz->PRINT((obj_Obj)__temp_var_0035);
		return (obj_Obj)(lit_false);
	goto end_typecase0000;
	end_typecase0000: ; /* Null statement */
	/* Typecase END */
	return (obj_Obj)(none);
}


obj_Nothing _main() {
	obj_Point pt;
	/* main Method Body */
	obj_Int __temp_var_0037 = int_literal(7);
	obj_Int __temp_var_0038 = int_literal(8);
	obj_Point __temp_var_0039 = new_Point((obj_Int)__temp_var_0037, (obj_Int)__temp_var_0038);
	pt = (obj_Point)(__temp_var_0039);
	obj_Obj __temp_var_0040 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)pt);
	obj_Int __temp_var_0041 = int_literal(5);
	obj_Obj __temp_var_0042 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)__temp_var_0041);
	obj_Obj __temp_var_0043 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)none);
	obj_Obj __temp_var_0044 = new_Obj();
	obj_Obj __temp_var_0045 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)__temp_var_0044);
	obj_Int __temp_var_0046 = int_literal(65);
	obj_Int __temp_var_0047 = int_literal(33);
	obj_Obj __temp_var_0048 = (obj_Obj)new_Point((obj_Int)__temp_var_0046, (obj_Int)__temp_var_0047);
	obj_Obj __temp_var_0049 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)__temp_var_0048);
	return none;
}

int main() {
	_main();
}
