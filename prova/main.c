#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myLib.h"

char* modify(char* s) {
	int i = 0;
	char* res;
	for (; s[i] != '\0'; i++);
	res = (char*)malloc(sizeof(char) * (i + 1));
	for (i = 0; s[i] != '\0'; i++) {
		if (i % 2 == 0)
			res[i] = *(s + i);
		else
			res[i] = 'o';
	}
	*(res + i) = '\0';
	return res;
}

int main() {
	char* stringa = "cane";
	char* post;
	post = modify(stringa);
	printf("%s\n", stringa);
	printf("%s\n", post);
	return 0;
}