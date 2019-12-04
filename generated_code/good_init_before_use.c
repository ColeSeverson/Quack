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
	obj_Nothing (*count)(obj_C1, obj_Int);
};

obj_C1 new_C1();
obj_Nothing C1_method_count(obj_C1 this, obj_Int x);

struct class_C1_struct the_class_C1_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C1_method_count
};

class_C1 the_class_C1 = &the_class_C1_struct;
obj_C1 new_C1() {
	obj_C1 this = (obj_C1)malloc(sizeof(struct obj_C1_struct));
	this->clazz = the_class_C1;
	/* Method statements */

	return this;
}

obj_Nothing C1_method_count(obj_C1 this, obj_Int x) {
	obj_Int count;
	obj_Int round;
	obj_Int __temp_var_0000 = int_literal(0);
	count = (obj_Int)(__temp_var_0000);
	obj_Int __temp_var_0001 = int_literal(50);
	round = (obj_Int)(__temp_var_0001);
	/* WHILE Loop Start */
	goto test_cond0000;
	loop_again0001: ; /* Null statement */
			obj_Int __temp_var_0002 = int_literal(0);
			obj_Boolean __temp_var_0003 = count->clazz->EQUALS((obj_Int)count, (obj_Obj)__temp_var_0002);
			if(lit_true == __temp_var_0003) { goto if0003; }
			goto else0004;
			/* True Part If */
			if0003: ; /* Null statement */
					obj_Int __temp_var_0004 = int_literal(0);
					x = (obj_Int)(__temp_var_0004);
			goto end_if0005;
			/* False Part If */
			else0004: ; /* Null statement */
			/* End If */
			end_if0005: ; /* Null statement */
			obj_Int __temp_var_0005 = int_literal(1);
			obj_Int __temp_var_0006 = count->clazz->PLUS((obj_Int)count, (obj_Int)__temp_var_0005);
			count = (obj_Int)(__temp_var_0006);
			obj_Int __temp_var_0007 = int_literal(1);
			obj_Int __temp_var_0008 = x->clazz->PLUS((obj_Int)x, (obj_Int)__temp_var_0007);
			x = (obj_Int)(__temp_var_0008);
	test_cond0000: ; /* Null statement */
	obj_Boolean __temp_var_0009 = x->clazz->LESS((obj_Int)x, (obj_Int)round);
	if(lit_true == __temp_var_0009) { goto loop_again0001; }
	goto end_while0002;
	end_while0002: ; /* Null statement */
	/* END WHILE Loop */
	return (obj_Nothing)(none);
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
