#include "reduceLib.h"
#include <stdio.h>

int reduce_for_int(int *array, int lengthOfArray, int initialValue, int (*callback)(int, int, int, int*)) {
	int count, result = 0;
	for (count = 0; count < lengthOfArray ; count++) {
		result = callback(initialValue, array[count], count, array);
		initialValue = result;
	}

	return result;
}

float reduce_for_float(float *array, int lengthOfArray, float initialValue, float (*callback)(float, float, int, float*)) {
	int count;
	float result = 0.0;
	
	for (count = 0; count < lengthOfArray; count++) {
		result = callback(initialValue, array[count], count, array);
		initialValue = result;
	}

	return result;
}

char reduce_for_char(char *array, int lengthOfArray, char initialValue, char (*callback)(char, char, int, char*)) {
	int count;
	char result;

	for (count = 0; count < lengthOfArray; count++) {
		result = callback(initialValue, array[count], count, array);
		initialValue = result;
	}

	return result;	
}

char* reduce_for_string(char **array, int lengthOfArray, char* initialValue, char* (*callback)(char*, char*, int, char**)){
	int count;
	char* result;

	for (count = 0; count < lengthOfArray; count++) {
		result = callback(initialValue, array[count], count, array);
		initialValue = result;
	}

	return result;	
}