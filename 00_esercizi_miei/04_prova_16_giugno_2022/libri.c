#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "libri.h"

Libro* leggiLibri(char fileName[], int* dim) {
	FILE* fp;
	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file doesn't exist.");
		*dim = 0;
		return NULL;
	}

	int righe = 1;
	char temp = fgetc(fp);

	while (temp != EOF) {
		if (temp == '\n') {
			righe++;
		}
		temp = fgetc(fp);
	}

	rewind(fp);
	
	Libro* elenco = malloc(righe * sizeof(Libro));

	int i;

	for (i = 0; i < righe; i++) {
		fscanf(fp, "%s ", elenco[i].ISBN);
		strcpy(elenco[i].titolo, leggi_fino_a(fp, ';'));
		fscanf(fp, " %d", &elenco[i].copie);
	}

	fclose(fp);

	*dim = righe;

	return elenco;

}

void stampaStore(Libro* elenco, int dim) {
	int i;
	for (i = 0; i < dim; i++) {
		printf("\nISBN: %s\tTitolo: %s\tCopie: %d", elenco[i].ISBN, elenco[i].titolo, elenco[i].copie);
	}
	printf("\n");
}

list leggiRichieste(char fileName[]) {

	list risultato = emptyList();

	FILE* fp;

	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file doesn't exist.");
		return risultato;
	}

	Richiesta temp;

	while (fscanf(fp, "%d ", &temp.cliente) != EOF) {
		strcpy(temp.titolo, leggi_fino_a(fp, ';'));
		fscanf(fp, "\n");
		risultato = cons(temp, risultato);
	}

	fclose(fp);

	return risultato;

}