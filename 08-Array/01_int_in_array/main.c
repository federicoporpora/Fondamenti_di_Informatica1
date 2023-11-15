#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input un numero non noto a priori di interi (al più 10) terminati da 0. Tale sequenza può eventualmente contenere numeri ripetuti.
    Si memorizzi tale sequenza in un vettore di opportuna dimensione.
    Si stampino a video tutti i numeri per cui il successivo nel vettore è pari al numero stesso
*/

#include <stdio.h>
#define DIM 10

int main() {

    int counter = 0;
    int n;
    int values[DIM];

    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n != 0 && counter < DIM) {
            values[counter] = n;
            counter++;
        }
        
    } while (counter < DIM && n != 0);

    for (int i = 0; i < counter - 1; i++) {
        if (values[i] == values[i + 1]) {
            printf("%d", values[i]);
        }
    }

    return 0;

}