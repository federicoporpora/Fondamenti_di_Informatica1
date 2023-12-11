#define _CRT_SECURE_NO_DEPRECATE

/*
	Un venditore di ortofrutta è solito fare credito ai propri clienti. Al fine di tenere traccia dei crediti, utilizza una
	funzione del registratore di cassa che salva, su un file binario di nome “ log.dat ”, strutture dati del tipo
	Transaction contenenti i seguenti dati:
		• una stringa customer, contenente il nome del cliente (al più 128
		caratteri, senza spazi);
		• un intero transactionId, recante un codice identificativo della
		transazione;
		• un float value, contenente l'ammontare del credito concesso.

	Al momento di riscuotere i crediti, il commerciante deve però poter accedere ai valori registrati nel file binario.
	A tal scopo, egli vuole avere un programma che, richiesto il nome del cliente, scriva su un file in formato testo gli
	importi relativi solo al cliente specificato.
	Inoltre il file deve avere come nome il nome del cliente con l ’ aggiunta dell ’ estensione “ .txt ” . Ad esempio, se
	il cliente richiesto si chiama “Federico”, allora il file dovrà chiamarsi “Federico.txt”.

	In un apposito modulo software, denominato “ registratore.h / registratore.c ”, dopo aver definito opportunamente le
	strutture dati necessarie, si realizzi una procedura
		void copy(FILE* source, FILE* dest, char *name, int *result);
	che, ricevuti in ingresso un puntatore source al file binario, un puntatore dest al file di testo, un puntatore a
	carattere name e un intero result passato per riferimento, copi su dest tutti gli importi presenti in source e relativi
	al cliente specificato con parametro name
	La funzione deve tenere traccia del numero di importi di credito copiati e deve restituire tale numero tramite il
	parametro result. Gli importi devono essere scritti su una sola linea, separati da uno spazio, con al termine un
	carattere di “newline” (‘\n’). Al fine di confrontare due stringhe, si utilizzi la funzione strcmp(…), che
	restituisce 0 se le due stringhe passate come parametri sono identiche

	Realizzare poi un programma “main.c” che chieda inizialmente all’utente il nome di un cliente. Per creare un opportuno
	nome per il file di destinazione, il candidato può utilizzare le funzioni di libreria:
		• strcpy(char *s, char *ct), che provvede a copiare la stringa ct nella stringa s;
		• strcat(char * s, char * ct), che concatena il contenuto della stringa ct in fondo alla stringa s (si faccia
		particolare attenzione a dimensionare opportunamente la stringa s per contenere i 4 caratteri
		dell ’ estensione “ .txt ” ). La stringa s, al termine dell ’ invocazione, è sempre una stringa ben formata
	Dopo aver aperto i file nell’opportuna modalità di lettura/scrittura, il programma utilizzi la funzione copy(…) definita
	al punto precedente per filtrare i dati. Il programma stampi infine a video il numero totale di crediti che sono stati
	copiati da un file all’altro
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "registratore.h"

int main() {

	char nome[DIM], nomeFile[DIM+4];
	int result;

	printf("Inserire il nome di un cliente: ");
	scanf("%s", &nome);

	strcpy(nomeFile, nome);
	strcat(nomeFile, ".txt");

	FILE* ftxt, * fbin;

	if ((fbin = fopen("log.dat", "rb")) == NULL) {
		printf("Il file non e' stato aperto correttamente.");
		exit(1);
	}

	if ((ftxt = fopen(nomeFile, "w")) == NULL) {
		printf("Il file non e' stato aperto correttamente.");
		exit(1);
	}

	copy(fbin, ftxt, nome, &result);

	fclose(fbin);
	fclose(ftxt);

	printf("%d records copied by log.dat to %s\n", result, nomeFile);

	return 0;

}