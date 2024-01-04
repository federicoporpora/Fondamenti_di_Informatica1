#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "funzioni.h"

#define SALDO_INIZIALE 400.0

int main() {

	int scelta, exit = 0;
	float mediaVers = 0, mediaPrel = 0, mediaAss = 0;
	float sommaVers = 0, sommaPrel = 0, sommaAss = 0, saldo = SALDO_INIZIALE;
	int countVers = 0, countPrel = 0, countAss = 0;
	
	while (exit == 0) {
		printf("\n\n***************************\n");
		printf("**********CALCOLO**********\n");
		printf("***************************\n\n");
		printf("***************************\n");
		printf("* Menu' utente principale *\n");
		printf("***************************\n");
		printf("* 1 Inserimento dati      *\n");
		printf("* 2 Media                 *\n");
		printf("* 3 Elabora               *\n");
		printf("* 4 Saldo                 *\n");
		printf("* 0 =====> USCITA         *\n");
		printf("***************************\n\n");
		printf("Inserire scelta (1, 2, 3, 4 oppure 0): ");
		scanf("%d", &scelta);

		switch (scelta)
		{
		case 1:
			if (leggiDati("transazioni.txt") != 0) {
				return 1;
			}
			else break;
		case 2:
			if (media(&mediaVers, &mediaPrel, &mediaAss, "transazioni.txt") != 0) {
				return 1;
			}
			else { 
				printf("\n\nMEDIE:\nVersamenti: %f eur\nPrelevamenti: %f eur\nAssegni: %f eur", mediaVers, mediaPrel, mediaAss);
				break;
			}
		case 3:
			if (elabora(&sommaVers, &sommaPrel, &sommaAss, "transazioni.txt", &countVers, &countPrel, &countAss) != 0) {
				return 1;
			}
			else {
				printf("\n\nSOMME E QUANTITA':\nVersamenti: %f eur, %d\nPrelevamenti: %f eur, %d\nAssegni: %f eur, %d", sommaVers, countVers, sommaPrel, countPrel, sommaAss, countAss);
				break;
			}
		case 4:
			if (saldoCalc(&sommaVers, &sommaPrel, &sommaAss, "transazioni.txt", &countVers, &countPrel, &countAss, &saldo) != 0) {
				return 1;
			}
			else {
				printf("\n\nSaldo: %f", saldo);
				break;
			}
		default:
			exit = 1;
			break;
		}
	}
	
	return 0;
}