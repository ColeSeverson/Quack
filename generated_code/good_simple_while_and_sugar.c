#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"


obj_Nothing _main() {
	obj_Int x;
	/* main Method Body */
	obj_Int __temp_var_0000 = int_literal(1);
	obj_Int * __temp_var_0001 = &(x);
	(*__temp_var_0001) = (obj_Int)(__temp_var_0000);
	/* WHILE Loop Start */
	goto test_cond0000;
	loop_again0001: ; /* Null statement */
			obj_Obj __temp_var_0002 = x->clazz->PRINT((obj_Obj)x);
			obj_String __temp_var_0003 = str_literal("\n");
			obj_Obj __temp_var_0004 = __temp_var_0003->clazz->PRINT((obj_Obj)__temp_var_0003);
			obj_Int __temp_var_0005 = int_literal(1);
			obj_Int __temp_var_0006 = x->clazz->PLUS((obj_Int)x, (obj_Int)__temp_var_0005);
			x = (obj_Int)(__temp_var_0006);
	test_cond0000: ; /* Null statement */
	obj_Int __temp_var_0007 = int_literal(10);
	obj_Boolean __temp_var_0008 = x->clazz->LESS((obj_Int)x, (obj_Int)__temp_var_0007);
	if(lit_true == __temp_var_0008) { goto loop_again0001; }
	goto end_while0002;
	end_while0002: ; /* Null statement */
	/* END WHILE Loop */
	obj_Int __temp_var_0009 = int_literal(12);
	x = (obj_Int)(__temp_var_0009);
	/* WHILE Loop Start */
	goto test_cond0003;
	loop_again0004: ; /* Null statement */
			obj_Obj __temp_var_0010 = x->clazz->PRINT((obj_Obj)x);
			obj_String __temp_var_0011 = str_literal("\n");
			obj_Obj __temp_var_0012 = __temp_var_0011->clazz->PRINT((obj_Obj)__temp_var_0011);
			obj_Int __temp_var_0013 = int_literal(1);
			obj_Int __temp_var_0014 = x->clazz->PLUS((obj_Int)x, (obj_Int)__temp_var_0013);
			x = (obj_Int)(__temp_var_0014);
	test_cond0003: ; /* Null statement */
	obj_Int __temp_var_0015 = int_literal(13);
	obj_Boolean __temp_var_0016 = x->clazz->ATMOST((obj_Int)x, (obj_Int)__temp_var_0015);
	if(lit_true == __temp_var_0016) { goto loop_again0004; }
	goto end_while0005;
	end_while0005: ; /* Null statement */
	/* END WHILE Loop */
	obj_Int __temp_var_0017 = int_literal(15);
	obj_Int * __temp_var_0018 = &(x);
	(*__temp_var_0018) = (obj_Int)(__temp_var_0017);
	/* WHILE Loop Start */
	goto test_cond0006;
	loop_again0007: ; /* Null statement */
			obj_Obj __temp_var_0019 = x->clazz->PRINT((obj_Obj)x);
			obj_String __temp_var_0020 = str_literal("\n");
			obj_Obj __temp_var_0021 = __temp_var_0020->clazz->PRINT((obj_Obj)__temp_var_0020);
			obj_Int __temp_var_0022 = int_literal(1);
			obj_Int __temp_var_0023 = x->clazz->MINUS((obj_Int)x, (obj_Int)__temp_var_0022);
			x = (obj_Int)(__temp_var_0023);
	test_cond0006: ; /* Null statement */
	obj_Int __temp_var_0024 = int_literal(10);
	obj_Boolean __temp_var_0025 = x->clazz->MORE((obj_Int)x, (obj_Int)__temp_var_0024);
	if(lit_true == __temp_var_0025) { goto loop_again0007; }
	goto end_while0008;
	end_while0008: ; /* Null statement */
	/* END WHILE Loop */
	obj_Int __temp_var_0026 = int_literal(4);
	x = (obj_Int)(__temp_var_0026);
	/* WHILE Loop Start */
	goto test_cond0009;
	loop_again0010: ; /* Null statement */
			obj_Obj __temp_var_0027 = x->clazz->PRINT((obj_Obj)x);
			obj_String __temp_var_0028 = str_literal("\n");
			obj_Obj __temp_var_0029 = __temp_var_0028->clazz->PRINT((obj_Obj)__temp_var_0028);
			obj_Int __temp_var_0030 = int_literal(1);
			obj_Int __temp_var_0031 = x->clazz->MINUS((obj_Int)x, (obj_Int)__temp_var_0030);
			x = (obj_Int)(__temp_var_0031);
	test_cond0009: ; /* Null statement */
	obj_Int __temp_var_0032 = int_literal(2);
	obj_Boolean __temp_var_0033 = x->clazz->ATLEAST((obj_Int)x, (obj_Int)__temp_var_0032);
	if(lit_true == __temp_var_0033) { goto loop_again0010; }
	goto end_while0011;
	end_while0011: ; /* Null statement */
	/* END WHILE Loop */
	obj_Int __temp_var_0034 = int_literal(0);
	x = (obj_Int)(__temp_var_0034);
	/* WHILE Loop Start */
	goto test_cond0012;
	loop_again0013: ; /* Null statement */
			obj_Obj __temp_var_0035 = x->clazz->PRINT((obj_Obj)x);
			obj_String __temp_var_0036 = str_literal("\n");
			obj_Obj __temp_var_0037 = __temp_var_0036->clazz->PRINT((obj_Obj)__temp_var_0036);
			obj_Int __temp_var_0038 = int_literal(1);
			obj_Int __temp_var_0039 = x->clazz->PLUS((obj_Int)x, (obj_Int)__temp_var_0038);
			x = (obj_Int)(__temp_var_0039);
	test_cond0012: ; /* Null statement */
	obj_Int __temp_var_0040 = int_literal(5);
	obj_Boolean __temp_var_0041 = x->clazz->EQUALS((obj_Int)x, (obj_Obj)__temp_var_0040);
	if(lit_true == __temp_var_0041) { goto end_while0014; }
	goto loop_again0013;
	end_while0014: ; /* Null statement */
	/* END WHILE Loop */
	return none;
}

int main() {
	_main();
}
