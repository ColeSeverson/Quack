#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"


obj_Nothing _main() {
	obj_Obj x;
	obj_Int y;
	/* main Method Body */
	obj_Int __temp_var_0000 = int_literal(0);
	obj_Int __temp_var_0001 = int_literal(564);
	obj_Int __temp_var_0002 = __temp_var_0000->clazz->MINUS((obj_Int)__temp_var_0000, (obj_Int)__temp_var_0001);
	obj_Obj * __temp_var_0003 = &(x);
	(*__temp_var_0003) = (obj_Obj)(__temp_var_0002);
	obj_Obj __temp_var_0004 = x->clazz->PRINT((obj_Obj)x);
	obj_String __temp_var_0005 = str_literal("\n");
	obj_Obj __temp_var_0006 = __temp_var_0005->clazz->PRINT((obj_Obj)__temp_var_0005);
	obj_Int __temp_var_0007 = int_literal(5);
	obj_Int __temp_var_0008 = int_literal(0);
	obj_Int __temp_var_0009 = int_literal(3);
	obj_Int __temp_var_0010 = __temp_var_0008->clazz->MINUS((obj_Int)__temp_var_0008, (obj_Int)__temp_var_0009);
	obj_Int __temp_var_0011 = __temp_var_0007->clazz->TIMES((obj_Int)__temp_var_0007, (obj_Int)__temp_var_0010);
	y = (obj_Int)(__temp_var_0011);
	obj_Obj __temp_var_0012 = y->clazz->PRINT((obj_Obj)y);
	obj_String __temp_var_0013 = str_literal("\n");
	obj_Obj __temp_var_0014 = __temp_var_0013->clazz->PRINT((obj_Obj)__temp_var_0013);
	return none;
}

int main() {
	_main();
}
