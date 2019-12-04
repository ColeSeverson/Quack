#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= Schroedinger =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_Schroedinger_struct;
typedef struct class_Schroedinger_struct* class_Schroedinger;

typedef struct obj_Schroedinger_struct {
	class_Schroedinger clazz;
	obj_Boolean living;
} * obj_Schroedinger;

struct class_Schroedinger_struct {
	class_Obj super_;
	obj_Schroedinger (*constructor)(obj_Int);
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_Schroedinger new_Schroedinger(obj_Int box);

struct class_Schroedinger_struct the_class_Schroedinger_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_Schroedinger,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_Schroedinger the_class_Schroedinger = &the_class_Schroedinger_struct;
obj_Schroedinger new_Schroedinger(obj_Int box) {
	obj_Schroedinger this = (obj_Schroedinger)malloc(sizeof(struct obj_Schroedinger_struct));
	this->clazz = the_class_Schroedinger;
	/* Method statements */
	obj_Int __temp_var_0000 = int_literal(0);
	obj_Boolean __temp_var_0001 = box->clazz->MORE((obj_Int)box, (obj_Int)__temp_var_0000);
	if(lit_true == __temp_var_0001) { goto if0000; }
	goto else0001;
	/* True Part If */
	if0000: ; /* Null statement */
			obj_Boolean * __temp_var_0002 = &(this->living);
			(*__temp_var_0002) = (obj_Boolean)(lit_true);
	goto end_if0002;
	/* False Part If */
	else0001: ; /* Null statement */
			obj_Boolean * __temp_var_0003 = &(this->living);
			(*__temp_var_0003) = (obj_Boolean)(lit_false);
	/* End If */
	end_if0002: ; /* Null statement */

	return this;
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
