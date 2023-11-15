#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input un numero non noto a priori di interi positivi (al più 10) terminati da 0.
    Si memorizzi tale sequenza in un vettore di opportuna dimensione, rispettando l’ordine con cui i valori sono stati inseriti.
    Si memorizzino poi in un secondo vettore i valori del primo, avendo cura di inserirli in ordine inverso
    Si stampi infine il vettore coi valori in ordine invertito
*/

#include <stdio.h>
#define DIM 10

int main() {

    int counter = 0;
    int n, i, j, values[DIM], inv[DIM];

    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n > 0 && counter < DIM) {
            values[counter] = n;
            counter++;
        }
    } while (n > 0 && counter < DIM);

    for (i = 0; i < counter; i++) {
        inv[i] = values[counter - i - 1];
    }

    for (j = 0; j < counter; j++) {
        printf("%d", inv[j]);
    }

    return 0;

}