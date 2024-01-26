#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "archivio.h"

int main() {

	int dim;
	char keyword[DIM_NOME];
	list leFoto;
	list noRep;
	Foto* arr;

	printf("Inserire una keyword: ");
	scanf("%s", keyword);
	leFoto = leggi_tutte_foto("archivio.txt");
	noRep = ripetuti(leFoto);
	arr = filtra(leFoto, keyword, &dim);
	printf("\n");
	stampaVettore(arr, dim);
	printf("\n");
	statistiche(arr, dim);

	freelist(leFoto);
	freelist(noRep);
	free(arr);

	return 0;
}