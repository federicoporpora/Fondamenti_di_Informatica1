#define _CRT_SECURE_NO_DEPRECATE

/*
    Al fine di stampare degli indirizzi su delle buste, è necessario comporre la prima parte dell’indirizzo
    come “Cognome Nome” o “Cognome N.”

    Si realizzi una funzione che riceva come parametri:
    – il cognome
    – il nome
    – una stringa di destinazione, che conterrà appunto la prima parte dell’indirizzo (“Cognome Nome”, o
        “Cognome N.”)
    – la lunghezza massima della stringa di destinazione

    La funzione deve copiare/concatenare nell’indirizzo il cognome seguito dal nome, avendo cura di
    rispettare le dimensioni della stringa indirizzo. Qualora la stringa indirizzo sia troppo piccola
    per contenere entrambi, la funzione provi a comporre la stringa come “Cognome N.”
    
    Qualora neanche ciò sia possibile, la funzione ritorni un codice di errore opportuno (ad esempio -1)
    
    Se non si verifica nessun errore la funzione deve restituire un codice che indichi il successo.

    Si realizzi una funzione che riceva come parametri:
    – il cognome
    – il nome
    – una stringa che conterrà la prima parte dell’indirizzo
    – la lunghezza massima della stringa indirizzo
int indirizzo(char Cognome[], char Nome[], char Indirizzo[], int dim);

    Esempio: Se il cognome è Rossi e il nome è Mario e la dimensione dim = 15 allora la stringa Indirizzo sara’
    “Rossi Mario”. Se invece la dimensione fosse 8 allora la stringa indirizzo sarebbe “Rossi M.”. Se la
    dimensione fosse 5 allora verrebbe restituito un codice di errore -1

    Per la risoluzione di questo esercizio si possono utilizzare le funzioni disponibili nella
    libreria standard <string.h>.
    strlen() per determinare la lunghezza di una stringa
    strcat() o strcpy() per comporre in indirizzo la nuova stringa
    
    Si provi ad organizzare il progetto su più file...
*/

#include <stdio.h>
#include <string.h>

#include "controllo.h"
#define DIM 14

int main() {

    char nome[DIM], cognome[DIM], insieme[DIM];
    int successo;

    printf("Inserire il proprio nome: ");
    scanf("%s", &nome);
    printf("Inserire il proprio cognome: ");
    scanf("%s", &cognome);
    
    successo = indirizzo(cognome, nome, insieme, DIM);

    if (successo == -1) {
        printf("\nTroppo lungo\n");
        return 0;
    }
    
    printf("\nIndirizzo: %s\n", insieme);

    return 0;

}