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
	int i;
	azione minimo;
	minimo.apertura = src[0].apertura;
	minimo.chiusura = src[0].chiusura;
	minimo.giorno = src[0].giorno;
	strcpy(minimo.nome, src[0].nome);

	for (i = 1; i < dim; i++) {
		if (myMin(src[i].apertura, src[i].chiusura) < myMin(minimo.apertura, minimo.chiusura)) {
			minimo.apertura = src[i].apertura;
			minimo.chiusura = src[i].chiusura;
			minimo.giorno = src[i].giorno;
			strcpy(minimo.nome, src[i].nome);
		}
	}

	*val = myMin(minimo.apertura, minimo.chiusura);
	return minimo;

}

float myMin(float a, float b) {
	return (a < b) ? a : b;
}

azione trovaMax(azione src[], int dim, float* val) {
	int i;
	azione massimo;
	massimo.apertura = src[0].apertura;
	massimo.chiusura = src[0].chiusura;
	massimo.giorno = src[0].giorno;
	strcpy(massimo.nome, src[0].nome);

	for (i = 1; i < dim; i++) {
		if (myMax(src[i].apertura, src[i].chiusura) > myMax(massimo.apertura, massimo.chiusura)) {
			massimo.apertura = src[i].apertura;
			massimo.chiusura = src[i].chiusura;
			massimo.giorno = src[i].giorno;
			strcpy(massimo.nome, src[i].nome);
		}
	}

	*val = myMax(massimo.apertura, massimo.chiusura);
	return massimo;
}

float myMax(float a, float b) {
	return (a > b) ? a : b;
}