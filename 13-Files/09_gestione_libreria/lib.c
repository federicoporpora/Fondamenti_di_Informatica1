#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "lib.h"

auth creaAutore() {
	auth a;
	printf("Inserire il nome dell'autore: ");
	scanf("%s", a.nome);
	printf("Inserire il cognome dell'autore: ");
	scanf("%s", a.cognome);
	return a;
}

int creaLibro(libro *dest) {
	printf("Inserire il codice del libro: ");
	scanf("%d", &((*dest).codice));
	if ((*dest).codice == 0) {
		return -1;
	}
	printf("Inserire il titolo del libro: ");
	scanf("%s", (*dest).titolo);
	(*dest).autore = creaAutore();
	printf("Inserire il numero di copie: ");
	scanf("%d", &((*dest).copie));
	printf("\n");
	return 0;
}

int creaVettore(libro v[], int dim) {
	int i = 0;
	libro temp;
	while (creaLibro(&temp) == 0 && i < dim) {
		v[i] = temp;
		i++;
	}
	return i;
}

void ricercaLibro(libro v[], int len) {
	int temp;
	printf("\nInserire il codice del libro: ");
	scanf("%d", &temp);
	for (int i = 0; i < len; i++) {
		if (temp == v[i].codice) {
			printf("\nCodice: %d\tTitolo: %s\tAutore: %s %s\tCopie: %d\n", v[i].codice, v[i].titolo, v[i].autore.cognome, v[i].autore.nome, v[i].copie);
		}
	}
}

void caricaInBin(FILE* fb, libro arr[], int lenV) {
	fwrite(arr, sizeof(libro), lenV, fb);
}

void scaricaDaBin(FILE* fb, libro arr[], int dim, int lenV) {
	fseek(fb, lenV * sizeof(libro), SEEK_SET);
	fread(&arr[lenV], sizeof(libro), dim - lenV, fb);
}