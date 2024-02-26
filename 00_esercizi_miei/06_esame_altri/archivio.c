#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "archivio.h"

void stampaUnaFoto(Foto input) {
	printf("Id: %d\tNome: %s\tDescrizione: %s\n", input.id, input.nome, input.descr);
}

Foto leggi_una_foto(FILE* fp) {
	Foto result;
	if (fscanf(fp, "%d ", &result.id) != 1) result.id = -1;
	else {
		strcpy(result.nome, leggi_fino_a(fp, '@'));
		strcpy(result.descr, leggi_fino_a(fp, '@'));
	}
	fscanf(fp, "\n");
	return result;
}

list leggi_tutte_foto(char* fileName) {
	FILE* fp;
	list result;
	Foto temp;
	result = emptyList();
	fp = fopen(fileName, "rt");
	if (fp != NULL) {
		do {
			temp = leggi_una_foto(fp);
			if (temp.id != -1) 
			{
				result = cons(temp, result);
			}
		} while (temp.id != -1);
		fclose(fp);
		result = reverse(result);
	}
	return result;
}

void stampa_foto(list leFoto, char* autore) {
	list temp = leFoto;
	while (!empty(temp)) {
		if (strcmp(head(temp).nome, autore) == 0 || strcmp(autore, "") == 0) {
			stampaUnaFoto(head(temp));
		}
		temp = tail(temp);
	}
	freelist(temp);
}

Foto* filtra(list leFoto, char* keyword, int* dim) {
	Foto* result;
	list temp = leFoto;
	*dim = 0;
	while (!empty(temp)) {
		if (strstr(head(temp).descr, keyword) != NULL) {
			(*dim)++;
		}
		temp = tail(temp);
	}
	if (*dim == 0) {
		result = NULL;
		return result;
	}
	temp = leFoto;
	result = (Foto*)malloc(sizeof(Foto) * (*dim));
	int i;
	i = 0;
	while (!empty(temp)) {
		if (strstr(head(temp).descr, keyword) != NULL) {
			result[i] = head(temp);
			i++;
		}
		temp = tail(temp);
	}
	freelist(temp);
	return result;
}

void stampaVettore(Foto* arr, int dim) {
	for (int i = 0; i < dim; i++) {
		stampaUnaFoto(arr[i]);
	}
}

int isGreaterThan(Foto a, Foto b) {
	int nameCompare = strcmp(a.nome, b.nome);
	if (nameCompare != 0) {
		return nameCompare > 0;
	}
	else {
		return a.id > b.id;
	}
}

int isEqualTo(Foto a, Foto b) {
	if ((strcmp(a.nome, b.nome)) == 0) {
		if (a.id == b.id) {
			return 1;
		}
	}
	return 0;
}

void scambia(Foto* a, Foto* b) {
	Foto tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSortR(Foto* a, int iniz, int fine)
{
	int i, j, iPivot;
	Foto pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do
		{
			while (i < j && (!isGreaterThan(a[i], pivot) || isEqualTo(a[i], pivot))) i++;
			while (j > i && (isGreaterThan(a[j], pivot) || isEqualTo(a[j], pivot))) j--;
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);
		if (i != iPivot && !isEqualTo(a[i], a[iPivot]))
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	}
}


void ordina(Foto* leFoto, int dim) {
	quickSortR(leFoto, 0, dim - 1);
}

int isEqualToComplete(Foto a, Foto b) {
	if (a.id == b.id) {
		return 1;
	}
	return 0;
}

int member(Foto unaFoto, list leFoto) {
	if (leFoto == NULL) {
		return 0;
	}
	if (isEqualToComplete(unaFoto, head(leFoto))) {
		return 1;
	}
	return member(unaFoto, tail(leFoto));
}

list ripetuti(list leFoto) {
	list result = emptyList();
	while (!empty(leFoto)) {
		if (!member(head(leFoto), result)) {
			result = cons(head(leFoto), result);
		}
		leFoto = tail(leFoto);
	}
	return result;
}

void statistiche(Foto* leFoto, int dim) {
	ordina(leFoto, dim);
	int count = 0;
	char currentAuthor[DIM_NOME];
	strcpy(currentAuthor, leFoto[0].nome);
	for (int i = 0; i < dim; i++) {
		if (strcmp(leFoto[i].nome, currentAuthor) == 0) {
			count++;
		}
		else {
			printf("Autore: %s, Numero di foto: %d\n", currentAuthor, count);
			strcpy(currentAuthor, leFoto[i].nome);
			count = 1;
		}
	}
	printf("Autore: %s, Numero di foto: %d\n", currentAuthor, count);
}