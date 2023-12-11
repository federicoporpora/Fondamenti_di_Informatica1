#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "lib.h"
#include <stdlib.h>

#define DIM 20

int main() {

    int lenV, request;
    libro arr[DIM];

    printf("\t- - - INSERIMENTO LIBRI - - -\n\n");

    lenV = creaVettore(arr, DIM);

    FILE* fb;

    if ((fb = fopen("elenco.dat", "wb")) == NULL) {
        printf("Il file non e' stato aperto correttamente.");
        exit(-1);
    }

    caricaInBin(fb, arr, lenV);

    fclose(fb);

    if ((fb = fopen("elenco.dat", "rb")) == NULL) {
        printf("Il file non e' stato aperto correttamente.");
        exit(-2);
    }

    scaricaDaBin(fb, arr, DIM, lenV);

    fclose(fb);

    do {
        printf("\n\t- - - MENU - - -\n\nInserire il codice a seconda di cosa si vuole fare:\n");
        printf("\t1) Stampare tutti i libri presenti in libreria.\n");
        printf("\t2) Ricerca di un libro a seconda del codice.\n");
        printf("\t3) Ricerca libr in esaurimento.\n");
        printf("\t4) Uscire dal programma.\n");

        scanf("%d", &request);

        int soglia;

        switch (request) {
        case 1:
            printf("\n");
            for (int i = 0; i < lenV; i++) {
                printf("Libro %d:\nCodice: %d\tTitolo: %s\tAutore: %s %s\tCopie: %d\n\n", i + 1, arr[i].codice, arr[i].titolo, arr[i].autore.cognome, arr[i].autore.nome, arr[i].copie);
            }
            break;
        case 2:
            ricercaLibro(arr, lenV);
            break;
        case 3:
            printf("Inserire un valore soglia di copie: ");
            scanf("%d", &soglia);
            int j = 0;
            for (int i = 0; i < lenV; i++) {
                if (arr[i].copie < soglia) {
                    printf("Libro %d:\nCodice: %d\tTitolo: %s\tAutore: %s %s\tCopie: %d\n\n", j + 1, arr[i].codice, arr[i].titolo, arr[i].autore.cognome, arr[i].autore.nome, arr[i].copie);
                    j++;
                }
            }
            break;
        case 4:
            return 0;
        default:
            printf("Hai inserito un codice sbagliato, riprova.");
            request = -1;
        }
    } while (request == -1);

    return 0;

}