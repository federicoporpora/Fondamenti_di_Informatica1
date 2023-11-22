#define _CRT_SECURE_NO_DEPRECATE

/*
    Si realizzi un programma C che legga da utente i dati relativi ad alcuni corsi.
    In particolare, per ogni corso vengono dati:
    denominazione del corso: una stringa di 20 caratteri che riporta il nome del corso;
    cognome del docente: una stringa di 15 caratteri cherappresenta il cognome del docente del corso;
    iscritti: un intero che indica il numero di studenti chefrequentano il corso.
    Il programma deve stampare la denominazione del corso e il cognome del docente relativi a
    tutti i corsi che hanno il numero di iscritti maggiore o uguale alla media aritmetica
    degli iscritti (calcolata su tutti i corsi).
*/

#include <stdio.h>
#define N 30

typedef struct {
    char denominazione[21];
    char cognome[16];
    int iscritti;
} corso;

int main() {

    char request, i = 0, j;
    double media = 0;
    corso corsi[N];

    do {
        printf("\nSi vuole inserire un corso? (Y/N) ");
        scanf(" %c", &request);
        if (request == 'Y' && i < N) {
            printf("Inserire il nome del corso: ");
            scanf("%s", &corsi[i].denominazione);
            printf("Inserire il cognome del professore: ");
            scanf("%s", &corsi[i].cognome);
            printf("Inserire il numero di iscritti: ");
            scanf("%d", &corsi[i].iscritti);
            i++;
        }
    } while (request == 'Y' && i < N);

    for (j = 0; j < i; j++) {
        media += corsi[j].iscritti;
    }
    media /= j;

    for (j = 0; j < i; j++) {
        if (corsi[j].iscritti > media) {
            printf("\nCorso sopra la media: %s del/la professore/ssa %s\n", corsi[j].denominazione, corsi[j].cognome);
        }
    }

    return 0;

}