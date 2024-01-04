#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "libri.h"

int main() {

	FILE* fp = aperturaFile("store.txt", "r");

	printf("%s", leggi_fino_a(fp, ';'));

	return 0;
}