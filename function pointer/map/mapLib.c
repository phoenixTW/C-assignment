#include "mapLib.h"
#include <stdio.h>

int* map_for_int (int *array, int length, int (*callback)(int, int, int *)) {
	int count, *resultArray;

	resultArray = (int *)malloc(sizeof(int) * length);

	for (count = 0; count < length; count++) {
		resultArray[count] = callback(array[count], count, array);
	}

	return resultArray;
}

float* map_for_float (float *array, int length, float (*callback)(float, int, float *)) {
	int count;
	float *resultArray;

	resultArray = (float *)malloc(sizeof(float) * length);

	for (count = 0; count < length; count++) {
		resultArray[count] = callback(array[count], count, array);
	}

	return resultArray;
}

char* map_for_char (char *array, int length, int (*callback)(char, int, char *)) {
	int count;
	char *resultArray;

	resultArray = (char *)malloc(sizeof(char) * length);

	for (count = 0; count < length; count++) {
		resultArray[count] = callback(array[count], count, array);
	}

	return resultArray;
}