#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input un numero non noto a priori di interi positivi (al più 10) terminati da 0.
    Qualora l’utente inserisca dei valori negativi, tali valori dovranno essere scartati e non considerati
    Si memorizzi tale sequenza in un vettore di opportuna dimensione.
    Si stampino a video tutti i numeri che sono allocati nel vettore in posizioni il cui indice è uguale al numero stesso
*/

#include <stdio.h>
#define DIM 10

int main() {

    int counter = 0;
    int n, i;
    int values[DIM];

    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n > 0 && counter < DIM) {
            values[counter] = n;
            counter++;
        }
    } while (n > 0 && counter < DIM);

    for (i = 0; i < counter; i++) {
        if (i == values[i]) {
            printf("%d ", values[i]);
        }
    }

    return 0;

}