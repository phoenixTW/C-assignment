#include "indexofLib.h"
#include <stdio.h>
#include <string.h>

int indexof(char *mainStr, char *subStr) {
	int count, startingIndex = 0, length = 0, subStrCount = 0, strLen = strlen(mainStr);

	for (count = 0; count < strLen; count++) {
		if(mainStr[count] == subStr[0]){
			startingIndex = count;
			break;
		}
	}

	length = startingIndex + strlen(subStr) - 1;

	for (count = startingIndex; count < length; count++) {
		if(mainStr[count] != subStr[subStrCount]){
			return -1;
		}
		subStrCount++;
	}

	return startingIndex;
}