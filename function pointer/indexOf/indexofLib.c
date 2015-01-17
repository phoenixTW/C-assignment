#include "indexofLib.h"
#include <stdio.h>
#include <string.h>

int indexof(char *string, char *subStr) {
	int indexOfString = 0, indexOfSubstr = 0, lengthOfString = strlen(string), lengthOfSubstr = strlen(subStr), index = -1;

	while(indexOfString + lengthOfSubstr <= lengthOfString) {
		index++;
		while(string[indexOfString] == subStr[indexOfSubstr] && indexOfSubstr < lengthOfSubstr){
			indexOfSubstr++;
			indexOfString++;
		}

		if(indexOfSubstr == lengthOfSubstr)
			return index;

		indexOfSubstr = 0;
		indexOfString = index;
		indexOfString++;
	}

	return -1;
}