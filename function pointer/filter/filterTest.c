#include "expr_assert.h"
#include "filterLib.h"

int filterNumbersGreaterThan2 (int number, int index, int *array) {
	return number > 2;
}

void test_filter_should_return_1_for_success() {
	int array[3] = {1, 2, 3};
	int *resultArray;
	int (*callback)(int, int, int*) = &filterNumbersGreaterThan2;
	assertEqual(filter(array, 3, &resultArray, callback), 1);
}

void test_filter_should_return_1_for_success_and_the_filtered_array() {
	int array[3] = {1, 2, 3};
	int *resultArray;
	int (*callback)(int, int, int*) = &filterNumbersGreaterThan2;
	assertEqual(filter(array, 3, &resultArray, callback), 1);
	assertEqual(resultArray[0], 3);
}

void test_filter_should_return_0_for_failure() {
	int array[0] = {};
	int *resultArray;
	int (*callback)(int, int, int*) = &filterNumbersGreaterThan2;
	assertEqual(filter(array, 0, &resultArray, callback), 0);
}

void test_filter_for_float_should_return_1_for_success() {
	float array[3] = {1.1, 2.2, 3.3};
	float *resultArray;

	int findGreaterThan (float number, int index, float *array) {
		return number > 1.4;
	}
	
	int (*callback)(float, int, float*) = &findGreaterThan;
	assertEqual(filter_for_float(array, 3, &resultArray, callback), 1);
}

void test_filter_for_float_should_return_1_for_success_and_result_array() {
	float array[3] = {1.1, 2.2, 3.3};
	float *resultArray;

	int findGreaterThan (float number, int index, float *array) {
		return number > 1.4;
	}
	
	int (*callback)(float, int, float*) = &findGreaterThan;
	assertEqual(filter_for_float(array, 3, &resultArray, callback), 1);
	assertEqual(resultArray[0], 2.2);
	assertEqual(resultArray[1], 3.3);
}

void test_filter_for_float_should_return_0_for_failure() {
	float array[0] = {};
	float *resultArray;

	int findGreaterThan (float number, int index, float *array) {
		return number > 1.4;
	}

	int (*callback)(float, int, float*) = &filterNumbersGreaterThan2;
	assertEqual(filter_for_float(array, 0, &resultArray, callback), 0);
}

void test_filter_for_char_should_return_1_for_success() {
	char array[3] = {'a', 'b', 'c'};
	char *resultArray;

	int isGreaterThanB (char charecter, int index, char *array) {
		return charecter > 'b';
	}

	int (*callback)(char, int, char*) = &isGreaterThanB;
	assertEqual(filter_for_char(&array, 3, &resultArray, callback), 1);
}

void test_filter_for_char_should_return_1_for_success_and_filtered_array () {
	char array[3] = {'a', 'b', 'c'};
	char *resultArray;

	int isGreaterThanB (char charecter, int index, char *array) {
		return charecter > 'a';
	}

	int (*callback)(char, int, char*) = &isGreaterThanB;
	assertEqual(filter_for_char(&array, 3, &resultArray, callback), 1);
	assertEqual(resultArray[0], 'b');
	assertEqual(resultArray[1], 'c');
}

void test_filter_for_char_should_return_0_for_failure() {
	char array[0] = {};
	char *resultArray;

	int isGreaterThanB (char charecter, int index, char *array) {
		return charecter > 'b';
	}

	int (*callback)(char, int, char*) = &isGreaterThanB;
	assertEqual(filter_for_char(&array, 0, &resultArray, callback), 0);
}

void test_filter_for_string_should_return_1_for_success() {
	char *array[3] = {"hello", "dog", "nice"};
	char *resultArray;

	int isOPresent (char charecter, int index, char *array) {
		return charecter > 'o';
	}

	int (*callback)(char, int, char*) = &isOPresent;
	assertEqual(filter_for_string(&array, 3, &resultArray, callback), 1);
}

void test_filter_for_string_should_return_1_for_success_and_resultant_array() {
	char *array[3] = {"hello", "dog", "nice"};
	char *resultArray;

	int isOPresent (char charecter, int index, char *array) {
		return charecter > 'o';
	}

	int (*callback)(char, int, char*) = &isOPresent;
	assertEqual(filter_for_string(&array, 3, &resultArray, callback), 1);
}
