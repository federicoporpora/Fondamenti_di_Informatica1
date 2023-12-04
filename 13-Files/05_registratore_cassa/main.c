#define _CRT_SECURE_NO_DEPRECATE

/*
	Un registratore di cassa registra su di un file binario alcuni dati relativi agli scontrini emessi.
	In particolare, tramite una struttura dati di nome scontrino, il registratore di cassa tiene traccia
	dell’importo(un float) e del numero di oggetti acquistati(un intero).
	
	In un apposito file registratore.h, si definisca una struttura dati “scontrino” atta a contenere / rappresentare
	i dati forniti dal registratore di cassa.
	
	In un apposito modulo software registratore.h / registratore.c, si devono realizzare due funzioni, una di
	lettura ed una di scrittura delle strutture dati scontrino:
		int leggi(FILE* fp, scontrino* dest);
		int scrivi(FILE* fp, scontrino src);
	
	Si realizzi un programma main che apra il file binario reg.dat in scrittura, e poi simuli il funzionamento del
	registratore di cassa per testare il modulo registratore. In particolare il programma chieda all’utente di
	inserire coppie importo / numero di oggetti, e le registri sul file binario usando la funzione scrivi(…).
	L’utente può segnalare la fine dell’inserimento dei valori indicando una coppia 0.00 / 0, che ovviamente non
	deve essere registrata nel file.

	Terminata la fase di inserimento, il programma chiuda il file e lo ri - apra in lettura, e stampi a video tutte
	le coppie memorizzate(per la lettura, si utilizzi la funzione leggi(…))

	Al termine il main chiuda correttamente il file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "registratore.h"

int main() {

	FILE* f1, * f2;
	scontrino base;
	int n = 0;

	if ((f1 = fopen("reg.dat", "wb")) == NULL) {
		printf("Il file non e' stato aperto correttamente.");
		exit(-1);
	}

	do {
		printf("Inserire una coppia importo/numero di oggetti: ");
		scanf("%f/%d", &base.importo, &base.nOggetti);
		if (base.importo != 0.0 || base.nOggetti != 0) {
			scrivi(f1, base);
		}
	} while (base.importo != 0. || base.nOggetti != 0 || f1 == EOF);

	fclose(f1);

	if ((f2 = fopen("reg.dat", "rb")) == NULL) {
		printf("Il file non e' stato aperto correttamente.");
		exit(-1);
	}

	int i = 0;

	while (leggi(f2, &base) > 0) {
		printf("Prezzo: %.2f, pezzi: %d\n", base.importo, base.nOggetti);
	}


	fclose(f2);

	return 0;

}