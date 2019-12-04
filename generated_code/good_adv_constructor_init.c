#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= C1_Fer =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_C1_Fer_struct;
typedef struct class_C1_Fer_struct* class_C1_Fer;

typedef struct obj_C1_Fer_struct {
	class_C1_Fer clazz;
} * obj_C1_Fer;

struct class_C1_Fer_struct {
	class_Obj super_;
	obj_C1_Fer (*constructor)(obj_Int, obj_Boolean, obj_String);
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
};

obj_C1_Fer new_C1_Fer(obj_Int x, obj_Boolean y, obj_String z);

struct class_C1_Fer_struct the_class_C1_Fer_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1_Fer,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR
};

class_C1_Fer the_class_C1_Fer = &the_class_C1_Fer_struct;
obj_C1_Fer new_C1_Fer(obj_Int x, obj_Boolean y, obj_String z) {
	obj_C1_Fer this = (obj_C1_Fer)malloc(sizeof(struct obj_C1_Fer_struct));
	this->clazz = the_class_C1_Fer;	obj_Boolean w;

	/* Method statements */
	/* WHILE Loop Start */
	goto test_cond0000;
	loop_again0001: ; /* Null statement */
			obj_Boolean * __temp_var_0000 = &(w);
			(*__temp_var_0000) = (obj_Boolean)(lit_true);
	test_cond0000: ; /* Null statement */
	obj_Int __temp_var_0001 = int_literal(5);
	obj_Boolean __temp_var_0002 = x->clazz->MORE((obj_Int)x, (obj_Int)__temp_var_0001);
	if(lit_true == __temp_var_0002) { goto loop_again0001; }
	goto end_while0002;
	end_while0002: ; /* Null statement */
	/* END WHILE Loop */
	return (obj_C1_Fer)(this);

	return this;
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
