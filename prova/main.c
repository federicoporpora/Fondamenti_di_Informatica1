#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myLib.h"

#define DIM 64

int main() {
	list root = NULL, l;
	int i;
	do {
		printf("\nIntrodurre valore :");
		scanf("%d", &i);
		root = insert(i, root);
	} while (i != 0);
	
	l = root; // stampa
	
	while (l != NULL) {
		printf("\nValore estratto : \t % d", l->value);
		l = l->next;
	}
}