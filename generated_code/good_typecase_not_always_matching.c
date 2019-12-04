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
} * obj_Point;

struct class_Point_struct {
	class_Obj super_;
	obj_Point (*constructor)(obj_Int, obj_Int);
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_Obj (*type_case)(obj_Point, obj_Obj);
};

obj_Point new_Point(obj_Int x, obj_Int y);
obj_Obj Point_method_type_case(obj_Point this, obj_Obj other);

struct class_Point_struct the_class_Point_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_Point,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	Point_method_type_case
};

class_Point the_class_Point = &the_class_Point_struct;
obj_Point new_Point(obj_Int x, obj_Int y) {
	obj_Point this = (obj_Point)malloc(sizeof(struct obj_Point_struct));
	this->clazz = the_class_Point;
	/* Method statements */

	return this;
}

obj_Obj Point_method_type_case(obj_Point this, obj_Obj other) {
	obj_Nothing y;
	obj_Int z;
	/* Typecase START */
	/* Typecase Type - Nothing */
	typecase_Nothing_0001: ; /* Null statement */
	if(!is_subtype(other->clazz, (class_Obj)(&the_class_Nothing_struct))) { goto typecase_Int_0002; }
		y = (obj_Nothing)(other);
		obj_String __temp_var_0000 = str_literal("Nothing received.\n");
		obj_Obj __temp_var_0001 = __temp_var_0000->clazz->PRINT((obj_Obj)__temp_var_0000);
		obj_Obj __temp_var_0002 = y->clazz->PRINT((obj_Obj)y);
		obj_String __temp_var_0003 = str_literal("\n");
		obj_Obj __temp_var_0004 = __temp_var_0003->clazz->PRINT((obj_Obj)__temp_var_0003);
		return (obj_Obj)(none);
	goto end_typecase0000;
	/* Typecase Type - Int */
	typecase_Int_0002: ; /* Null statement */
	if(!is_subtype(other->clazz, (class_Obj)(&the_class_Int_struct))) { goto end_typecase0000; }
		z = (obj_Int)(other);
		obj_String __temp_var_0005 = str_literal("Int received.\n");
		obj_Obj __temp_var_0006 = __temp_var_0005->clazz->PRINT((obj_Obj)__temp_var_0005);
		obj_Obj __temp_var_0007 = z->clazz->PRINT((obj_Obj)z);
		obj_String __temp_var_0008 = str_literal("\n");
		obj_Obj __temp_var_0009 = __temp_var_0008->clazz->PRINT((obj_Obj)__temp_var_0008);
		return (obj_Obj)(none);
	goto end_typecase0000;
	end_typecase0000: ; /* Null statement */
	/* Typecase END */
	obj_String __temp_var_0010 = str_literal("No match found\n");
	obj_Obj __temp_var_0011 = __temp_var_0010->clazz->PRINT((obj_Obj)__temp_var_0010);
	return (obj_Obj)(none);
}


obj_Nothing _main() {
	obj_Point pt;
	/* main Method Body */
	obj_Int __temp_var_0012 = int_literal(7);
	obj_Int __temp_var_0013 = int_literal(8);
	obj_Point __temp_var_0014 = new_Point((obj_Int)__temp_var_0012, (obj_Int)__temp_var_0013);
	pt = (obj_Point)(__temp_var_0014);
	obj_Obj __temp_var_0015 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)pt);
	obj_Int __temp_var_0016 = int_literal(5);
	obj_Obj __temp_var_0017 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)__temp_var_0016);
	obj_Obj __temp_var_0018 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)none);
	obj_Obj __temp_var_0019 = new_Obj();
	obj_Obj __temp_var_0020 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)__temp_var_0019);
	obj_Int __temp_var_0021 = int_literal(65);
	obj_Int __temp_var_0022 = int_literal(33);
	obj_Obj __temp_var_0023 = (obj_Obj)new_Point((obj_Int)__temp_var_0021, (obj_Int)__temp_var_0022);
	obj_Obj __temp_var_0024 = pt->clazz->type_case((obj_Point)pt, (obj_Obj)__temp_var_0023);
	return none;
}

int main() {
	_main();
}
