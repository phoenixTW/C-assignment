#include "expr_assert.h"
#include "reduceLib.h"
void test_reduce_for_int_should_return_6_when_the_initial_value_is_0 () {
	int result;
	int array[3] = {1, 2, 3};

	int add (int previousValue, int currentValue) {
		return previousValue + currentValue;
	}

	int (*callback)(int, int) = &add;

	assertEqual(reduce_for_int(array, 3, 0, callback), 6);
}

void test_reduce_for_int_should_return_6_as_a_greater_value_in_the_array () {
	int result;
	int array[6] = {1, 2, 3, 6, 4, 5};

	int add (int previousValue, int currentValue) {
		return (previousValue > currentValue) ? previousValue : currentValue;
	}

	int (*callback)(int, int) = &add;

	assertEqual(reduce_for_int(array, 6, 0, callback), 6);
}

void test_reduce_for_int_should_return_6_as_a_smallest_value_in_the_array () {
	int result;
	int array[6] = {1, 2, 3, 6, 4, 5};

	int isGreater (int previousValue, int currentValue) {
		return (previousValue < currentValue) ? previousValue : currentValue;
	}

	int (*callback)(int, int) = &isGreater;

	assertEqual(reduce_for_int(array, 6, 7, callback), 1);
}

float giveGreatest (float previousValue, float currentValue) {
    return (previousValue > currentValue) ? previousValue : currentValue;
}

void test_reduce_for_float_should_return_9_as_a_greatest_value_in_the_array () {
    float array[6] = {1.3, 2.8, 9.3, 1.6, 4.9, 5.3};
    int array_length = 6;
    float (*p)(float, float) = &giveGreatest;
    assertEqual(reduce_for_float(array, array_length, 0, p), 9.3);
}

void test_reduce_for_float_should_return_6_point_6_when_the_initial_value_is_0 () {
	float array[3] = {1.1, 2.2, 3.3}, result;

	float addFloat (float previousValue, float currentValue) {
		return previousValue + currentValue;
	}

	float (*callback)(float, float) = &addFloat;
	result = reduce_for_float(array, 3, 0, callback);
	assertEqual(reduce_for_float(array, 3, 0, callback), 6.6);
}
