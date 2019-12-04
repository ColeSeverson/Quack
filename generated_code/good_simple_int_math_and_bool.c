#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"


obj_Nothing _main() {
	/* main Method Body */
	obj_Int __temp_var_0000 = int_literal(5);
	obj_Int __temp_var_0001 = int_literal(4);
	obj_Int __temp_var_0002 = __temp_var_0000->clazz->PLUS((obj_Int)__temp_var_0000, (obj_Int)__temp_var_0001);
	obj_Obj __temp_var_0003 = __temp_var_0002->clazz->PRINT((obj_Obj)__temp_var_0002);
	obj_String __temp_var_0004 = str_literal("\n");
	obj_Obj __temp_var_0005 = __temp_var_0004->clazz->PRINT((obj_Obj)__temp_var_0004);
	obj_Int __temp_var_0006 = int_literal(95);
	obj_Int __temp_var_0007 = int_literal(5);
	obj_Int __temp_var_0008 = __temp_var_0006->clazz->DIVIDE((obj_Int)__temp_var_0006, (obj_Int)__temp_var_0007);
	obj_Obj __temp_var_0009 = __temp_var_0008->clazz->PRINT((obj_Obj)__temp_var_0008);
	obj_String __temp_var_0010 = str_literal("\n");
	obj_Obj __temp_var_0011 = __temp_var_0010->clazz->PRINT((obj_Obj)__temp_var_0010);
	obj_Int __temp_var_0012 = int_literal(5);
	obj_Int __temp_var_0013 = int_literal(6);
	obj_Int __temp_var_0014 = __temp_var_0012->clazz->TIMES((obj_Int)__temp_var_0012, (obj_Int)__temp_var_0013);
	obj_Obj __temp_var_0015 = __temp_var_0014->clazz->PRINT((obj_Obj)__temp_var_0014);
	obj_String __temp_var_0016 = str_literal("\n");
	obj_Obj __temp_var_0017 = __temp_var_0016->clazz->PRINT((obj_Obj)__temp_var_0016);
	obj_Int __temp_var_0018 = int_literal(3);
	obj_Int __temp_var_0019 = int_literal(20);
	obj_Int __temp_var_0020 = __temp_var_0018->clazz->MINUS((obj_Int)__temp_var_0018, (obj_Int)__temp_var_0019);
	obj_Obj __temp_var_0021 = __temp_var_0020->clazz->PRINT((obj_Obj)__temp_var_0020);
	obj_String __temp_var_0022 = str_literal("\n");
	obj_Obj __temp_var_0023 = __temp_var_0022->clazz->PRINT((obj_Obj)__temp_var_0022);
	obj_Obj __temp_var_0024 = lit_true->clazz->PRINT((obj_Obj)lit_true);
	obj_String __temp_var_0025 = str_literal("\n");
	obj_Obj __temp_var_0026 = __temp_var_0025->clazz->PRINT((obj_Obj)__temp_var_0025);
	obj_Obj __temp_var_0027 = lit_false->clazz->PRINT((obj_Obj)lit_false);
	obj_String __temp_var_0028 = str_literal("\n");
	obj_Obj __temp_var_0029 = __temp_var_0028->clazz->PRINT((obj_Obj)__temp_var_0028);
	obj_Obj __temp_var_0030 = none->clazz->PRINT((obj_Obj)none);
	obj_String __temp_var_0031 = str_literal("\n");
	obj_Obj __temp_var_0032 = __temp_var_0031->clazz->PRINT((obj_Obj)__temp_var_0031);
	return none;
}

int main() {
	_main();
}
