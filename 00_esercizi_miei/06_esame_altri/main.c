#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "archivio.h"

int main() {

	// es 1
	//FILE* fp = fopen("archivio.txt", "r");
	//Foto puppa = leggi_una_foto(fp);
	//stampaUnaFoto(puppa);

	//list leFoto = emptyList();
	//leFoto = leggi_tutte_foto("archivio.txt");
	//stampa_foto(leFoto, "");


	// es 2
	Foto* array;
	int dim;
	list leFoto = emptyList();
	leFoto = leggi_tutte_foto("archivio.txt");
	array = filtra(leFoto, "calcio", &dim);
	ordina(leFoto, dim);
	for (int i = 0; i < dim; i++) {
		stampaUnaFoto(array[i]);
	}

	return 0;
}