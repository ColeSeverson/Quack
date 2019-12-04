#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"

/*======================= ShortCircuitChecker =======================*/
/* Typedefs Required for Separation of class and object structs */
struct class_ShortCircuitChecker_struct;
typedef struct class_ShortCircuitChecker_struct* class_ShortCircuitChecker;

typedef struct obj_ShortCircuitChecker_struct {
	class_ShortCircuitChecker clazz;
} * obj_ShortCircuitChecker;

struct class_ShortCircuitChecker_struct {
	class_Obj super_;
	obj_ShortCircuitChecker (*constructor)();
	obj_Boolean (*EQUALS)(obj_Obj, obj_Obj);
	obj_Obj (*PRINT)(obj_Obj);
	obj_String (*STR)(obj_Obj);
	obj_Boolean (*false_no_print)(obj_ShortCircuitChecker);
	obj_Boolean (*false_should_print)(obj_ShortCircuitChecker);
	obj_Boolean (*return_false)(obj_ShortCircuitChecker);
	obj_Boolean (*return_true)(obj_ShortCircuitChecker);
	obj_Boolean (*true_no_print)(obj_ShortCircuitChecker);
	obj_Boolean (*true_should_print)(obj_ShortCircuitChecker);
};

obj_ShortCircuitChecker new_ShortCircuitChecker();
obj_Boolean ShortCircuitChecker_method_false_no_print(obj_ShortCircuitChecker this);
obj_Boolean ShortCircuitChecker_method_false_should_print(obj_ShortCircuitChecker this);
obj_Boolean ShortCircuitChecker_method_return_false(obj_ShortCircuitChecker this);
obj_Boolean ShortCircuitChecker_method_return_true(obj_ShortCircuitChecker this);
obj_Boolean ShortCircuitChecker_method_true_no_print(obj_ShortCircuitChecker this);
obj_Boolean ShortCircuitChecker_method_true_should_print(obj_ShortCircuitChecker this);

struct class_ShortCircuitChecker_struct the_class_ShortCircuitChecker_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_ShortCircuitChecker,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	ShortCircuitChecker_method_false_no_print,
	ShortCircuitChecker_method_false_should_print,
	ShortCircuitChecker_method_return_false,
	ShortCircuitChecker_method_return_true,
	ShortCircuitChecker_method_true_no_print,
	ShortCircuitChecker_method_true_should_print
};

class_ShortCircuitChecker the_class_ShortCircuitChecker = &the_class_ShortCircuitChecker_struct;
obj_ShortCircuitChecker new_ShortCircuitChecker() {
	obj_ShortCircuitChecker this = (obj_ShortCircuitChecker)malloc(sizeof(struct obj_ShortCircuitChecker_struct));
	this->clazz = the_class_ShortCircuitChecker;
	/* Method statements */

	return this;
}

obj_Boolean ShortCircuitChecker_method_false_no_print(obj_ShortCircuitChecker this) {
	obj_String __temp_var_0000 = str_literal("False should not print\n");
	obj_Obj __temp_var_0001 = __temp_var_0000->clazz->PRINT((obj_Obj)__temp_var_0000);
	return (obj_Boolean)(lit_false);
}

obj_Boolean ShortCircuitChecker_method_false_should_print(obj_ShortCircuitChecker this) {
	obj_String __temp_var_0002 = str_literal("False Printed\n");
	obj_Obj __temp_var_0003 = __temp_var_0002->clazz->PRINT((obj_Obj)__temp_var_0002);
	return (obj_Boolean)(lit_false);
}

obj_Boolean ShortCircuitChecker_method_return_false(obj_ShortCircuitChecker this) {
	return (obj_Boolean)(lit_false);
}

obj_Boolean ShortCircuitChecker_method_return_true(obj_ShortCircuitChecker this) {
	return (obj_Boolean)(lit_true);
}

obj_Boolean ShortCircuitChecker_method_true_no_print(obj_ShortCircuitChecker this) {
	obj_String __temp_var_0004 = str_literal("True should not print\n");
	obj_Obj __temp_var_0005 = __temp_var_0004->clazz->PRINT((obj_Obj)__temp_var_0004);
	return (obj_Boolean)(lit_true);
}

obj_Boolean ShortCircuitChecker_method_true_should_print(obj_ShortCircuitChecker this) {
	obj_String __temp_var_0006 = str_literal("True Printed\n");
	obj_Obj __temp_var_0007 = __temp_var_0006->clazz->PRINT((obj_Obj)__temp_var_0006);
	return (obj_Boolean)(lit_true);
}


obj_Nothing _main() {
	obj_ShortCircuitChecker x;
	/* main Method Body */
	obj_ShortCircuitChecker __temp_var_0008 = new_ShortCircuitChecker();
	x = (obj_ShortCircuitChecker)(__temp_var_0008);
	/* Generate OR */
		goto if0000;	halfway0003: ; /* Null statement */
		obj_Boolean __temp_var_0009 = x->clazz->true_no_print((obj_ShortCircuitChecker)x);
		if(lit_true == __temp_var_0009) { goto if0000; }
		goto else0001;
	/* True Part If */
	if0000: ; /* Null statement */
			obj_String __temp_var_0010 = str_literal("SUCCESS_1\n");
			obj_Obj __temp_var_0011 = __temp_var_0010->clazz->PRINT((obj_Obj)__temp_var_0010);
	goto end_if0002;
	/* False Part If */
	else0001: ; /* Null statement */
			obj_String __temp_var_0012 = str_literal("ERROR_1\n");
			obj_Obj __temp_var_0013 = __temp_var_0012->clazz->PRINT((obj_Obj)__temp_var_0012);
	/* End If */
	end_if0002: ; /* Null statement */
	/* Generate AND */
		goto halfway0007;	halfway0007: ; /* Null statement */
		obj_Boolean __temp_var_0014 = x->clazz->true_should_print((obj_ShortCircuitChecker)x);
		if(lit_true == __temp_var_0014) { goto if0004; }
		goto else0005;
	/* True Part If */
	if0004: ; /* Null statement */
			obj_String __temp_var_0015 = str_literal("SUCCESS_2\n");
			obj_Obj __temp_var_0016 = __temp_var_0015->clazz->PRINT((obj_Obj)__temp_var_0015);
	goto end_if0006;
	/* False Part If */
	else0005: ; /* Null statement */
			obj_String __temp_var_0017 = str_literal("ERROR_2\n");
			obj_Obj __temp_var_0018 = __temp_var_0017->clazz->PRINT((obj_Obj)__temp_var_0017);
	/* End If */
	end_if0006: ; /* Null statement */
	/* Generate AND */
		goto else0009;	halfway0011: ; /* Null statement */
		obj_Boolean __temp_var_0019 = x->clazz->true_no_print((obj_ShortCircuitChecker)x);
		if(lit_true == __temp_var_0019) { goto if0008; }
		goto else0009;
	/* True Part If */
	if0008: ; /* Null statement */
			obj_String __temp_var_0020 = str_literal("ERROR_3\n");
			obj_Obj __temp_var_0021 = __temp_var_0020->clazz->PRINT((obj_Obj)__temp_var_0020);
	goto end_if0010;
	/* False Part If */
	else0009: ; /* Null statement */
			obj_String __temp_var_0022 = str_literal("SUCCESS_3\n");
			obj_Obj __temp_var_0023 = __temp_var_0022->clazz->PRINT((obj_Obj)__temp_var_0022);
	/* End If */
	end_if0010: ; /* Null statement */
	/* Generate OR */
		goto halfway0015;	halfway0015: ; /* Null statement */
		obj_Boolean __temp_var_0024 = x->clazz->true_should_print((obj_ShortCircuitChecker)x);
		if(lit_true == __temp_var_0024) { goto if0012; }
		goto else0013;
	/* True Part If */
	if0012: ; /* Null statement */
			obj_String __temp_var_0025 = str_literal("SUCCESS_4\n");
			obj_Obj __temp_var_0026 = __temp_var_0025->clazz->PRINT((obj_Obj)__temp_var_0025);
	goto end_if0014;
	/* False Part If */
	else0013: ; /* Null statement */
			obj_String __temp_var_0027 = str_literal("ERROR_4\n");
			obj_Obj __temp_var_0028 = __temp_var_0027->clazz->PRINT((obj_Obj)__temp_var_0027);
	/* End If */
	end_if0014: ; /* Null statement */
	/* Generate OR */
		goto halfway0019;	halfway0019: ; /* Null statement */
		obj_Boolean __temp_var_0029 = x->clazz->false_should_print((obj_ShortCircuitChecker)x);
		if(lit_true == __temp_var_0029) { goto if0016; }
		goto else0017;
	/* True Part If */
	if0016: ; /* Null statement */
			obj_String __temp_var_0030 = str_literal("ERROR_5\n");
			obj_Obj __temp_var_0031 = __temp_var_0030->clazz->PRINT((obj_Obj)__temp_var_0030);
	goto end_if0018;
	/* False Part If */
	else0017: ; /* Null statement */
			obj_String __temp_var_0032 = str_literal("SUCCESS_5\n");
			obj_Obj __temp_var_0033 = __temp_var_0032->clazz->PRINT((obj_Obj)__temp_var_0032);
	/* End If */
	end_if0018: ; /* Null statement */
	obj_Boolean __temp_var_0034 = x->clazz->return_false((obj_ShortCircuitChecker)x);
	obj_Boolean __temp_var_0035 = lit_false->clazz->EQUALS((obj_Boolean)lit_false, (obj_Boolean)__temp_var_0034);
	if(lit_true == __temp_var_0035) { goto if0020; }
	goto else0021;
	/* True Part If */
	if0020: ; /* Null statement */
			obj_String __temp_var_0036 = str_literal("False Singleton Success\n");
			obj_Obj __temp_var_0037 = __temp_var_0036->clazz->PRINT((obj_Obj)__temp_var_0036);
	goto end_if0022;
	/* False Part If */
	else0021: ; /* Null statement */
			obj_String __temp_var_0038 = str_literal("False Singleton Error\n");
			obj_Obj __temp_var_0039 = __temp_var_0038->clazz->PRINT((obj_Obj)__temp_var_0038);
	/* End If */
	end_if0022: ; /* Null statement */
	obj_Boolean __temp_var_0040 = x->clazz->return_true((obj_ShortCircuitChecker)x);
	obj_Boolean __temp_var_0041 = lit_true->clazz->EQUALS((obj_Boolean)lit_true, (obj_Boolean)__temp_var_0040);
	if(lit_true == __temp_var_0041) { goto if0023; }
	goto else0024;
	/* True Part If */
	if0023: ; /* Null statement */
			obj_String __temp_var_0042 = str_literal("True Singleton Success\n");
			obj_Obj __temp_var_0043 = __temp_var_0042->clazz->PRINT((obj_Obj)__temp_var_0042);
	goto end_if0025;
	/* False Part If */
	else0024: ; /* Null statement */
			obj_String __temp_var_0044 = str_literal("True Singleton Error\n");
			obj_Obj __temp_var_0045 = __temp_var_0044->clazz->PRINT((obj_Obj)__temp_var_0044);
	/* End If */
	end_if0025: ; /* Null statement */
	obj_Boolean __temp_var_0046 = x->clazz->return_false((obj_ShortCircuitChecker)x);
	obj_Boolean __temp_var_0047 = lit_true->clazz->EQUALS((obj_Boolean)lit_true, (obj_Boolean)__temp_var_0046);
	if(lit_true == __temp_var_0047) { goto if0026; }
	goto else0027;
	/* True Part If */
	if0026: ; /* Null statement */
			obj_String __temp_var_0048 = str_literal("Singleton not equal error\n");
			obj_Obj __temp_var_0049 = __temp_var_0048->clazz->PRINT((obj_Obj)__temp_var_0048);
	goto end_if0028;
	/* False Part If */
	else0027: ; /* Null statement */
			obj_String __temp_var_0050 = str_literal("Singleton not equal success\n");
			obj_Obj __temp_var_0051 = __temp_var_0050->clazz->PRINT((obj_Obj)__temp_var_0050);
	/* End If */
	end_if0028: ; /* Null statement */
	return none;
}

int main() {
	_main();
}
