#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "funzioni.h"

int leggiDati(char * fileName) {
	FILE* fp;
	if ((fp = fopen(fileName, "w")) == NULL) {
		perror("The file doesn't exist.");
		return 1;
	}
	
	int x, temp;

	printf("Inserire il numero di versamenti: "); // versamenti
	scanf("%d", &x);
	srand(time(NULL));

	for (int i = 0; i < x; i++) {
		temp = rand() % 200;
		if (i == x - 1) {
			fprintf(fp, "%d\n", temp);
		}
		else {
			fprintf(fp, "%d ", temp);
		}
	}

	printf("Inserire il numero di prelevamenti: "); // prelevamenti
	scanf("%d", &x);

	for (int i = 0; i < x; i++) {
		temp = rand() % 200;
		if (i == x - 1) {
			fprintf(fp, "%d\n", temp);
		}
		else {
			fprintf(fp, "%d ", temp);
		}
	}

	printf("Inserire il numero di assegni: "); // assegni
	scanf("%d", &x);

	for (int i = 0; i < x; i++) {
		temp = rand() % 200;
		if (i == x - 1) {
			fprintf(fp, "%d\n", temp);
		}
		else {
			fprintf(fp, "%d ", temp);
		}
	}

	fclose(fp);

	return 0;

}

int media(float* mediaVers, float* mediaPrel, float* mediaAss, char* fileName) {
	FILE* fp;
	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file doesn't exist.");
		return 1;
	}

	*mediaVers = *mediaPrel = *mediaAss = 0;
	int countVers = 0, countPrel = 0, countAss = 0;
	char line[1000];

	while (fgets(line, sizeof(line), fp) != NULL) {
		int temp;
		if (sscanf(line, "%d", &temp) == 1) {
			if (countVers % 3 == 0) {
				*mediaVers += temp;
				countVers++;
			}
			else if (countPrel % 3 == 1) {
				*mediaPrel += temp;
				countPrel++;
			}
			else if (countAss % 3 == 2) {
				*mediaAss += temp;
				countAss++;
			}
		}
	}

	// Calcola le medie
	*mediaVers /= countVers;
	*mediaPrel /= countPrel;
	*mediaAss /= countAss;

	fclose(fp);
	return 0;
}

int elabora(float* sommaVers, float* sommaPrel, float* sommaAss, char* fileName, int *countVers, int *countPrel, int *countAss) {
	FILE* fp;
	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file doesn't exist.");
		return 1;
	}

	*sommaVers = *sommaPrel = *sommaAss = 0;
	*countVers = 0, *countPrel = 0, *countAss = 0;
	char line[1000];

	while (fgets(line, sizeof(line), fp) != NULL) {
		int temp;
		if (sscanf(line, "%d", &temp) == 1) {
			if ((*countVers) % 3 == 0) {
				*sommaVers += temp;
				(*countVers)++;
			}
			else if ((*countPrel) % 3 == 1) {
				*sommaPrel += temp;
				(*countPrel)++;
			}
			else if ((*countAss) % 3 == 2) {
				*sommaAss += temp;
				(*countAss)++;
			}
		}
	}

	fclose(fp);
	return 0;
}

int saldoCalc(float* sommaVers, float* sommaPrel, float* sommaAss, char* fileName, int* countVers, int* countPrel, int* countAss, float* saldo) {
	FILE* fp;
	if ((fp = fopen(fileName, "r")) == NULL) {
		perror("The file doesn't exist.");
		return 1;
	}

	*sommaVers = *sommaPrel = *sommaAss = 0;
	*countVers = 0, * countPrel = 0, * countAss = 0;
	char line[1000];

	while (fgets(line, sizeof(line), fp) != NULL) {
		int temp;
		if (sscanf(line, "%d", &temp) == 1) {
			if ((*countVers) % 3 == 0) {
				*sommaVers += temp;
				(*countVers)++;
			}
			else if ((*countPrel) % 3 == 1) {
				*sommaPrel += temp;
				(*countPrel)++;
			}
			else if ((*countAss) % 3 == 2) {
				*sommaAss += temp;
				(*countAss)++;
			}
		}
	}

	*saldo += *sommaVers;
	*saldo -= *sommaAss;
	*saldo -= *sommaPrel;

	fclose(fp);
	return 0;
}