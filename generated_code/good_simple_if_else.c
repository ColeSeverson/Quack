#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"


obj_Nothing _main() {
	obj_String x;
	/* main Method Body */
	goto if0000;	/* True Part If */
	if0000: ; /* Null statement */
			obj_String __temp_var_0000 = str_literal("This should print1\n");
			obj_Obj __temp_var_0001 = __temp_var_0000->clazz->PRINT((obj_Obj)__temp_var_0000);
	goto end_if0002;
	/* False Part If */
	else0001: ; /* Null statement */
			obj_String __temp_var_0002 = str_literal("This should NOT print\n");
			obj_Obj __temp_var_0003 = __temp_var_0002->clazz->PRINT((obj_Obj)__temp_var_0002);
	/* End If */
	end_if0002: ; /* Null statement */
	goto else0004;	/* True Part If */
	if0003: ; /* Null statement */
			obj_String __temp_var_0004 = str_literal("This should NOT print\n");
			obj_Obj __temp_var_0005 = __temp_var_0004->clazz->PRINT((obj_Obj)__temp_var_0004);
	goto end_if0005;
	/* False Part If */
	else0004: ; /* Null statement */
			goto else0007;			/* True Part If */
			if0006: ; /* Null statement */
					obj_String __temp_var_0006 = str_literal("This should also NOT print\n");
					obj_Obj __temp_var_0007 = __temp_var_0006->clazz->PRINT((obj_Obj)__temp_var_0006);
			goto end_if0008;
			/* False Part If */
			else0007: ; /* Null statement */
					obj_String __temp_var_0008 = str_literal("This should print2\n");
					obj_Obj __temp_var_0009 = __temp_var_0008->clazz->PRINT((obj_Obj)__temp_var_0008);
			/* End If */
			end_if0008: ; /* Null statement */
	/* End If */
	end_if0005: ; /* Null statement */
	obj_String __temp_var_0010 = str_literal("Hello World");
	x = (obj_String)(__temp_var_0010);
	obj_String __temp_var_0011 = str_literal("Hello World");
	obj_Boolean __temp_var_0012 = x->clazz->EQUALS((obj_String)x, (obj_Obj)__temp_var_0011);
	if(lit_true == __temp_var_0012) { goto if0009; }
	goto else0010;
	/* True Part If */
	if0009: ; /* Null statement */
			obj_String __temp_var_0013 = str_literal("This should print3\n");
			obj_Obj __temp_var_0014 = __temp_var_0013->clazz->PRINT((obj_Obj)__temp_var_0013);
	goto end_if0011;
	/* False Part If */
	else0010: ; /* Null statement */
			obj_String __temp_var_0015 = str_literal("This should NOT print\n");
			obj_Obj __temp_var_0016 = __temp_var_0015->clazz->PRINT((obj_Obj)__temp_var_0015);
	/* End If */
	end_if0011: ; /* Null statement */
	obj_String __temp_var_0017 = str_literal("Hello World");
	obj_Boolean __temp_var_0018 = x->clazz->EQUALS((obj_String)x, (obj_Obj)__temp_var_0017);
	if(lit_true == __temp_var_0018) { goto else0013; }
	goto if0012;
	/* True Part If */
	if0012: ; /* Null statement */
			obj_String __temp_var_0019 = str_literal("This should NOT print\n");
			obj_Obj __temp_var_0020 = __temp_var_0019->clazz->PRINT((obj_Obj)__temp_var_0019);
	goto end_if0014;
	/* False Part If */
	else0013: ; /* Null statement */
			obj_String __temp_var_0021 = str_literal("This should print4\n");
			obj_Obj __temp_var_0022 = __temp_var_0021->clazz->PRINT((obj_Obj)__temp_var_0021);
	/* End If */
	end_if0014: ; /* Null statement */
	return none;
}

int main() {
	_main();
}
