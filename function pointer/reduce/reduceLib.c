#include "reduceLib.h"
#include <stdio.h>

int reduce_for_int(int *array, int lengthOfArray, int initialValue, int (*callback)(int, int)) {
	int count, result = 0;
	for (count = 0; count < lengthOfArray ; count++) {
		result = callback(initialValue, array[count]);
		initialValue = result;
	}

	return result;
}

float reduce_for_float(float *array, int lengthOfArray, float initialValue, float (*callback)(float, float)) {
	int count;
	float result = 0.0;
	
	for (count = 0; count < lengthOfArray; count++) {
		result = callback(initialValue, array[count]);
		initialValue = result;
	}

	return result;
}
