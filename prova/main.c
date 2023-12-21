#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myLib.h"
#include "list.h"

int main() {
	list l1 = emptyList();
	int el;
	do {
		printf("\n Introdurre valore : \t");
		scanf("%d", &el);
		l1 = cons(el, l1);
	} while (el != 0); // condizione arbitraria
	showList(l1);
}