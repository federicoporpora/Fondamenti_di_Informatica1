#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "azioni.h"
#include <string.h>

int leggi(FILE* fp, azione dest[], int dim, char* nome) {
	char name[64];
	float apertura, chiusura;
	int giorno, temp, i;

	i = 0;
	do {
		if ((temp = fscanf(fp, "%s %f%f%d\n", name, &apertura, &chiusura, &giorno)) != EOF && (strcmp(name, nome)) == 0 && i < dim) {
			dest[i].apertura = apertura;
			dest[i].chiusura = chiusura;
			dest[i].giorno = giorno;
			strcpy(dest[i].nome, name);
			i++;
		}
	} while (temp != EOF && i < dim);

	return i + 1;
}

azione trovaMin(azione src[], int dim, float* val) {
	if (dim <= 0) {
		// Se l'array è vuoto, restituisci una struttura vuota
		azione empty = { 0 };
		*val = 0.0;
		return empty;
	}

	int i;

	azione minimo = src[0]; // Assume il primo elemento come minimo

	for (i = 1; i < dim; i++) {
		float minimoAttuale = (src[i].apertura < src[i].chiusura) ? src[i].apertura : src[i].chiusura;
		float minimoCorrente = (minimo.apertura < minimo.chiusura) ? minimo.apertura : minimo.chiusura;

		if (minimoAttuale < minimoCorrente) {
			minimo = src[i];
		}
	}

	*val = (minimo.apertura < minimo.chiusura) ? minimo.apertura : minimo.chiusura;
	return minimo;
}

float myMin(float a, float b) {
	return (a < b) ? a : b;
}

azione trovaMax(azione src[], int dim, float* val) {

	if (dim <= 0) {
		// Se l'array è vuoto, restituisci una struttura vuota
		azione empty = { 0 };
		*val = 0.0;
		return empty;
	}

	int i;

	azione massimo = src[0]; // Assume il primo elemento come massimo

	for (i = 1; i < dim; i++) {
		float massimoAttuale = (src[i].apertura > src[i].chiusura) ? src[i].apertura : src[i].chiusura;
		float massimoCorrente = (massimo.apertura > massimo.chiusura) ? massimo.apertura : massimo.chiusura;

		if (massimoAttuale > massimoCorrente) {
			massimo = src[i];
		}
	}

	*val = myMax(massimo.apertura, massimo.chiusura);
	return massimo;
}

float myMax(float a, float b) {
	return (a > b) ? a : b;
}