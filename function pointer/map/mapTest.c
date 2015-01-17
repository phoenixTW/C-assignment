#include "expr_assert.h"
#include "mapLib.h"
#include <string.h>

void test_map_for_int_should_return_a_new_array () {
	int array[3] = {1, 2, 3};
	int *resultArray;

	int add5 (int number, int index, int *array) {
		return number + 5;
	}
	
	int (*callback)(int, int, int*) = &add5;

	resultArray = map_for_int(array, 3, callback);

	assertEqual(resultArray[0], 6);
	assertEqual(resultArray[1], 7);
	assertEqual(resultArray[2], 8);
}

void test_map_for_float_should_return_a_new_array () {
	float array[3] = {1.1, 2.1, 3.1};
	float *resultArray;

	float add5Point2 (float number, int index, float *array) {
		return number + 5.2;
	}
	
	float (*callback)(float, int, float*) = &add5Point2;

	resultArray = map_for_float(array, 3, callback);

	assertEqual(resultArray[0], 6.3);
	assertEqual(resultArray[1], 7.3);
	assertEqual(resultArray[2], 8.3);
}

void test_map_for_char_should_return_a_new_array () {
	char array[3] = {'a', 'b', 'c'};
	char *resultArray;

	int increaseBy2 (char letter, int index, char *array) {
		return letter + 2;
	}
	
	int (*callback)(char, int, char*) = &increaseBy2;

	resultArray = map_for_char(array, 3, callback);

	assertEqual(resultArray[0], 'c');
	assertEqual(resultArray[1], 'd');
	assertEqual(resultArray[2], 'e');
}

void test_map_for_string_should_return_a_new_array_with_uppercase_words () {
	char *array[2] = {"hello", "dog"};
	char **resultArray;

	char* toUpperCase (char* word, int index, char **array) {
		void strupp(char *s) {
			int i;
			for (i = 0; i < strlen(s); i++)
				s[i] = toupper(s[i]);
		}

		strupp(word);
		return word;
	}
	
	char* (*callback_for_string)(char*, int, char**) = &toUpperCase;

	resultArray = map_for_string(array, 2, callback_for_string);
}