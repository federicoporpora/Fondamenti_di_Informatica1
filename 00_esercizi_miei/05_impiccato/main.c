#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"

#define DIM_NOME 100
#define DIM_PAROLA 100

typedef struct {
	char nome[DIM_NOME];
	int punteggio;
} Giocatore;

int main() {

	Giocatore arr[1];
	Giocatore temp;

	int nPartite;

	printf("A che punteggio si vuole arrivare? ");
	scanf("%d", &nPartite);

	printf("\n\n- - IL PRIMO GIOCATORE AD ARRIVARE A %d VINCE - -", nPartite);

	printf("\nInserire il nome del giocatore 1: ");
	scanf("%s", temp.nome);
	temp.punteggio = 0;

	arr[0] = temp;

	printf("\nInserire il nome del giocatore 2: ");
	scanf("%s", temp.nome);
	temp.punteggio = 0;

	char parola[DIM_PAROLA];
	char* stampa;

	for (int i = 0; i < nPartite; i++) {
		printf("\n%s, inserisci la parola da indovinare: ", arr[0].nome);
		scanf("%s", parola);

		stampa = malloc((strlen(parola) + 1) * sizeof(char));
		for (int j = 0; j < strlen(parola); j++) {
			if (j % 2 == 0) {
				stampa[j] = '_';
			}
			else {
				stampa[j] = ' ';
			}
		}
		stampa[strlen(parola)] = '\0';

		printf("%s", stampa);

	}

	return 0;
}