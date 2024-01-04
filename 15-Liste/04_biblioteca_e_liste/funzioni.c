#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "myLib.h"
#include "funzioni.h"

int creaVettoreDaFile(FILE* fp, volume V[]) {
	char autore[24], titolo[56];
	int numero_possedute, numero_prestito, i;
	i = 0;
	while (fscanf(fp, "%s %s %d %d\n", autore, titolo, &numero_possedute, &numero_prestito) > 0) {
		strcpy(V[i].autore, autore);
		strcpy(V[i].titolo, titolo);
		V[i].numero_possedute = numero_possedute;
		V[i].numero_prestito = numero_prestito;
		i++;
	}
	return i;
}

void stampaV(volume V[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%s, %s, possedute: %d, prestito: %d\n", V[i].autore, V[i].titolo, V[i].numero_possedute, V[i].numero_prestito);
	}
}

list creaLista(volume V[], int len) {
	list L = emptyList();
	for (int i = len - 1; i >= 0; i--) {
		L = cons((V[i].numero_possedute - V[i].numero_prestito), L);
	}
	return L;
}

float stampaRapporti(volume V[], list L, int len) {
	float sommaDisponibili = 0;
	while (!empty(L)) {
		sommaDisponibili += head(L);
		L = tail(L);
	}

	float sommaPossedute = 0;

	for (int i = 0; i < len; i++) {
		sommaPossedute += V[i].numero_possedute;
	}

	if (sommaPossedute == 0) {
		return 0;
	}

	return sommaDisponibili / sommaPossedute;

}

int piuDisponibili(list L) {
	int riga = 0;
	int maxDisp = 0;
	int i = 1;
	while (!empty(L)) {
		if (head(L) > maxDisp) {
			riga = i;
			maxDisp = head(L);
		}
		L = tail(L);
		i++;
	}
	return riga;
}

void stampaRiga(FILE* fp, int riga) {
	char autore[24], titolo[56];
	int numero_possedute, numero_prestito;
	for (int i = 1; i < riga; i++) {
		fscanf(fp, "%*s %*s %*d %*d\n");
	}
	fscanf(fp, "%s %s %d %d\n", autore, titolo, &numero_possedute, &numero_prestito);
	printf("\nRiga:\n%s %s %d %d\n", autore, titolo, numero_possedute, numero_prestito);
}