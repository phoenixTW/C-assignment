#include "filterLib.h"
#include "string.h"
#include <stdio.h>

int filter(int *array, int length, int **resultArray, int (*callback)(int, int, int *)) {
	int count, numberOfBlocks;

	if(length < 1) return 0;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array))
			numberOfBlocks++;
	}

	*resultArray = (int *)malloc(sizeof(int) * numberOfBlocks);
	numberOfBlocks = -1;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array)){
			(*resultArray)[++numberOfBlocks] = array[count];
		}
	}

	return 1;
}

int filter_for_float(float *array, int length, float **resultArray, int (*callback)(float, int, float *)) {
	int count, numberOfBlocks;

	if(length < 1) return 0;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array))
			numberOfBlocks++;
	}

	*resultArray = (float *)malloc(sizeof(float) * numberOfBlocks);
	numberOfBlocks = -1;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array)){
			(*resultArray)[++numberOfBlocks] = array[count];
		}
	}

	return 1;
}

int filter_for_char(char *array, int length, char **resultArray, int (*callback)(char, int, char *)) {
	int count, numberOfBlocks;

	if(length < 1) return 0;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array)){
			numberOfBlocks++;
		}
	}

	*resultArray = (char *)malloc(sizeof(char) * numberOfBlocks);
	numberOfBlocks = -1;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, &array)){
			(*resultArray)[++numberOfBlocks] = array[count];
		}
	}

	return 1;
}

int filter_for_string(char **array, int length, char ***resultArray, int (*callback)(char*, int, char *)) {
	int count, newLength = 0;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array))
			newLength++;
	}

	*resultArray = (char **)malloc(sizeof(char *) * newLength);
	newLength = -1;

	for (count = 0; count < length; count++) {
		if(callback(array[count], count, array)) {
			(*resultArray)[++newLength] = array[count];
		}
	}

	return 1;
}