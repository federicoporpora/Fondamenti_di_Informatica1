#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "funzioni.h"

Evento leggiUno(FILE* fp) {
	Evento result;
	char ch;
	int i;
	if (fscanf(fp, "%d ", &(result.id)) == 1) {
		ch = fgetc(fp);
		i = 0;
		while (ch != '\n' && ch != EOF && ch != '@' && i < DIM - 1) {
			result.entr[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		result.entr[i] = '\0';

		ch = fgetc(fp);
		i = 0;
		while (ch != '\n' && ch != EOF && ch != '@' && i < DIM - 1) {
			result.exit[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		result.exit[i] = '\0';
	}
	else {
		result.id = -1;
	}
	return result;
}

list leggiTutti(char* fileName) {
	FILE* fp;
	list result = emptyList();
	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file didn't open properly.");
		return emptyList();
	}
	Evento temp;
	do {
		temp = leggiUno(fp);
		if (temp.id != -1) {
			result = cons(temp, result);
		}
	} while (temp.id != -1);
	result = reverse(result);
	fclose(fp);
	return result;
}

Tariffa* leggiTariffe(char* fileName, int* dim) {
	FILE* fp;
	*dim = 0;
	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file didn't open properly.");
		return NULL;
	}

	char ch;

	(*dim) = 1;

	while (fscanf(fp, "%c", &ch) > 0) {
		if (ch == '\n') (*dim)++;
	}

	Tariffa* V;

	V = malloc((*dim) * (sizeof(Tariffa)));

	if (V == NULL) {
		perror("Error in memory allocation");
		(*dim) = 0;
		return NULL;
	}

	rewind(fp);

	int i, j;

	j = -1;

	do {
		j++;
		ch = fgetc(fp);
		i = 0;
		while (ch != '\n' && ch != EOF && ch != '@' && i < DIM - 1) {
			V[j].entr[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		V[j].entr[i] = '\0';

		ch = fgetc(fp);
		i = 0;
		while (ch != '\n' && ch != EOF && ch != '@' && i < DIM - 1) {
			V[j].exit[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		V[j].exit[i] = '\0';
	} while (fscanf(fp, "%f", &V[j].price) != EOF);

	fclose(fp);

	return V;
}