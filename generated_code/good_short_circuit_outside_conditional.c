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
	obj_Nothing (*GetBoolean)(obj_C1, obj_Boolean);
	obj_Boolean (*ShouldNotPrint)(obj_C1);
	obj_Boolean (*ShouldPrint)(obj_C1);
};

obj_C1 new_C1();
obj_Nothing C1_method_GetBoolean(obj_C1 this, obj_Boolean in);
obj_Boolean C1_method_ShouldNotPrint(obj_C1 this);
obj_Boolean C1_method_ShouldPrint(obj_C1 this);

struct class_C1_struct the_class_C1_struct = {
	(class_Obj)&the_class_Obj_struct,
	new_C1,
	Obj_method_EQUALS,
	Obj_method_PRINT,
	Obj_method_STR,
	C1_method_GetBoolean,
	C1_method_ShouldNotPrint,
	C1_method_ShouldPrint
};

class_C1 the_class_C1 = &the_class_C1_struct;
obj_C1 new_C1() {
	obj_C1 this = (obj_C1)malloc(sizeof(struct obj_C1_struct));
	this->clazz = the_class_C1;
	/* Method statements */

	return this;
}

obj_Nothing C1_method_GetBoolean(obj_C1 this, obj_Boolean in) {
	obj_Obj __temp_var_0000 = in->clazz->PRINT((obj_Obj)in);
	obj_String __temp_var_0001 = str_literal("\n");
	obj_Obj __temp_var_0002 = __temp_var_0001->clazz->PRINT((obj_Obj)__temp_var_0001);
	return (obj_Nothing)(none);
}

obj_Boolean C1_method_ShouldNotPrint(obj_C1 this) {
	obj_String __temp_var_0003 = str_literal("THIS SHOULD NOT PRINT\n");
	obj_Obj __temp_var_0004 = __temp_var_0003->clazz->PRINT((obj_Obj)__temp_var_0003);
	return (obj_Boolean)(lit_true);
}

obj_Boolean C1_method_ShouldPrint(obj_C1 this) {
	obj_String __temp_var_0005 = str_literal("Good\n");
	obj_Obj __temp_var_0006 = __temp_var_0005->clazz->PRINT((obj_Obj)__temp_var_0005);
	return (obj_Boolean)(lit_true);
}


obj_Nothing _main() {
	obj_C1 x;
	/* main Method Body */
	obj_C1 __temp_var_0007 = new_C1();
	x = (obj_C1)(__temp_var_0007);
	obj_Boolean __temp_var_0008 = lit_false;
	/* and Left Condition */
		obj_Int __temp_var_0009 = int_literal(5);
		obj_Int __temp_var_0010 = int_literal(4);
		obj_Boolean __temp_var_0011 = __temp_var_0009->clazz->EQUALS((obj_Int)__temp_var_0009, (obj_Obj)__temp_var_0010);
		if(lit_true == __temp_var_0011) { goto and_HALFWAY0000; }
		goto and_END0002;
	and_HALFWAY0000: ; /* Null statement */	/* and Right Condition */
		obj_Boolean __temp_var_0012 = x->clazz->ShouldNotPrint((obj_C1)x);
		if(lit_true == __temp_var_0012) { goto and_TRUE0001; }
		goto and_END0002;
	/* Boolean Get True */
	and_TRUE0001: ; /* Null statement */
	__temp_var_0008 = lit_true;
	and_END0002: ; /* Null statement */
	/* and End */
	obj_Nothing __temp_var_0013 = x->clazz->GetBoolean((obj_C1)x, (obj_Boolean)__temp_var_0008);
	obj_Boolean __temp_var_0014 = lit_false;
	/* and Left Condition */
		obj_String __temp_var_0015 = str_literal("Hello");
		obj_String __temp_var_0016 = str_literal("Hello");
		obj_Boolean __temp_var_0017 = __temp_var_0015->clazz->EQUALS((obj_String)__temp_var_0015, (obj_Obj)__temp_var_0016);
		if(lit_true == __temp_var_0017) { goto and_HALFWAY0003; }
		goto and_END0005;
	and_HALFWAY0003: ; /* Null statement */	/* and Right Condition */
		obj_Boolean __temp_var_0018 = x->clazz->ShouldPrint((obj_C1)x);
		if(lit_true == __temp_var_0018) { goto and_TRUE0004; }
		goto and_END0005;
	/* Boolean Get True */
	and_TRUE0004: ; /* Null statement */
	__temp_var_0014 = lit_true;
	and_END0005: ; /* Null statement */
	/* and End */
	obj_Nothing __temp_var_0019 = x->clazz->GetBoolean((obj_C1)x, (obj_Boolean)__temp_var_0014);
	obj_Boolean __temp_var_0020 = lit_false;
	/* and Left Condition */
		obj_String __temp_var_0021 = str_literal("Hello");
		obj_String __temp_var_0022 = str_literal("World");
		obj_Boolean __temp_var_0023 = __temp_var_0021->clazz->EQUALS((obj_String)__temp_var_0021, (obj_Obj)__temp_var_0022);
		if(lit_true == __temp_var_0023) { goto and_HALFWAY0006; }
		goto and_END0008;
	and_HALFWAY0006: ; /* Null statement */	/* and Right Condition */
		obj_Boolean __temp_var_0024 = x->clazz->ShouldNotPrint((obj_C1)x);
		if(lit_true == __temp_var_0024) { goto and_TRUE0007; }
		goto and_END0008;
	/* Boolean Get True */
	and_TRUE0007: ; /* Null statement */
	__temp_var_0020 = lit_true;
	and_END0008: ; /* Null statement */
	/* and End */
	obj_Nothing __temp_var_0025 = x->clazz->GetBoolean((obj_C1)x, (obj_Boolean)__temp_var_0020);
	obj_Boolean __temp_var_0026 = lit_false;
	/* or Left Condition */
		obj_String __temp_var_0027 = str_literal("Hello");
		obj_String __temp_var_0028 = str_literal("Hello");
		obj_Boolean __temp_var_0029 = __temp_var_0027->clazz->EQUALS((obj_String)__temp_var_0027, (obj_Obj)__temp_var_0028);
		if(lit_true == __temp_var_0029) { goto or_TRUE0010; }
		goto or_HALFWAY0009;
	or_HALFWAY0009: ; /* Null statement */	/* or Right Condition */
		obj_Boolean __temp_var_0030 = x->clazz->ShouldNotPrint((obj_C1)x);
		if(lit_true == __temp_var_0030) { goto or_TRUE0010; }
		goto or_END0011;
	/* Boolean Get True */
	or_TRUE0010: ; /* Null statement */
	__temp_var_0026 = lit_true;
	or_END0011: ; /* Null statement */
	/* or End */
	obj_Nothing __temp_var_0031 = x->clazz->GetBoolean((obj_C1)x, (obj_Boolean)__temp_var_0026);
	obj_Boolean __temp_var_0032 = lit_false;
	/* or Left Condition */
		obj_String __temp_var_0033 = str_literal("Hello");
		obj_String __temp_var_0034 = str_literal("World");
		obj_Boolean __temp_var_0035 = __temp_var_0033->clazz->EQUALS((obj_String)__temp_var_0033, (obj_Obj)__temp_var_0034);
		if(lit_true == __temp_var_0035) { goto or_TRUE0013; }
		goto or_HALFWAY0012;
	or_HALFWAY0012: ; /* Null statement */	/* or Right Condition */
		obj_Boolean __temp_var_0036 = x->clazz->ShouldPrint((obj_C1)x);
		if(lit_true == __temp_var_0036) { goto or_TRUE0013; }
		goto or_END0014;
	/* Boolean Get True */
	or_TRUE0013: ; /* Null statement */
	__temp_var_0032 = lit_true;
	or_END0014: ; /* Null statement */
	/* or End */
	obj_Nothing __temp_var_0037 = x->clazz->GetBoolean((obj_C1)x, (obj_Boolean)__temp_var_0032);
	return none;
}

int main() {
	_main();
}
