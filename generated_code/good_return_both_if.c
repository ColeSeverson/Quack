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
	obj_Int (*return_test)(obj_C1);
};

obj_C1 new_C1();
obj_Int C1_method_return_test(obj_C1 this);

struct class_C1_struct the_class_C1_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C1_method_return_test
};

class_C1 the_class_C1 = &the_class_C1_struct;
obj_C1 new_C1() {
	obj_C1 this = (obj_C1)malloc(sizeof(struct obj_C1_struct));
	this->clazz = the_class_C1;
	/* Method statements */

	return this;
}

obj_Int C1_method_return_test(obj_C1 this) {
	goto if0000;	/* True Part If */
	if0000: ; /* Null statement */
			obj_Int __temp_var_0000 = int_literal(34);
			obj_Int __temp_var_0001 = int_literal(34343);
			obj_Int __temp_var_0002 = __temp_var_0000->clazz->PLUS((obj_Int)__temp_var_0000, (obj_Int)__temp_var_0001);
			return (obj_Int)(__temp_var_0002);
	goto end_if0002;
	/* False Part If */
	else0001: ; /* Null statement */
			obj_Int __temp_var_0003 = int_literal(43);
			obj_Int __temp_var_0004 = int_literal(3432);
			obj_Int __temp_var_0005 = __temp_var_0003->clazz->DIVIDE((obj_Int)__temp_var_0003, (obj_Int)__temp_var_0004);
			return (obj_Int)(__temp_var_0005);
	/* End If */
	end_if0002: ; /* Null statement */
}


obj_Nothing _main() {
	/* main Method Body */
	return none;
}

int main() {
	_main();
}
