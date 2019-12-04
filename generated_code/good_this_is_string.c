#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"


obj_Nothing _main() {
	/* main Method Body */
	obj_String __temp_var_0000 = str_literal("This is a string\n");
	obj_Obj __temp_var_0001 = __temp_var_0000->clazz->PRINT((obj_Obj)__temp_var_0000);
	return none;
}

int main() {
	_main();
}
