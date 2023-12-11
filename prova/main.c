#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myLib.h"

#define DIM 64

int main() {

	char stringa[DIM];

	printf("Inserire la stringa con spazi: ");
	strConSpazi(stringa, DIM);

	printf("%s", stringa);

	return 0;

}