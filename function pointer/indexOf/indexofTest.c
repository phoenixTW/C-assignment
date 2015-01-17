#include "expr_assert.h"
#include "indexofLib.h"

void test_indexof_str_is_0_in_string () {
	char *mainString = "String";
	char *sub_str = "Str";
	assertEqual(indexof(mainString, sub_str), 0);
};

void test_indexof_str_is_2_in_string () {
	char *mainString = "String";
	char *sub_str = "rin";
	assertEqual(indexof(mainString, sub_str), 2);
};

void test_indexof_str_is_minus_1_when_sub_string_is_not_matching_with_string () {
	char *mainString = "String";
	char *sub_str = "ren";
	assertEqual(indexof(mainString, sub_str), -1);
};

void test_indexof_str_is_minus_0_when_sub_string_is_matching_where_same_letter_present_for_multiple_time () {
	char *mainString = "session";
	char *sub_str = "sio";
	assertEqual(indexof(mainString, sub_str), 3);
};
