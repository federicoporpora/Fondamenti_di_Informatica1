#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input un numero non noto a priori di interi (al più 10) terminati da 0. Tale sequenza potrà eventualmente contenere numeri ripetuti.
    A tal fine, si realizzi una funzione apposita che riceva in ingresso un vettore (vuoto) e la sua dimensione fisica, e restituisca la dimensione logica.
    Si chieda poi l’inserimento di un valore k da cercare nell’array.
    Si realizzi una procedura che stampi a video tutti gli indici relativi alle posizioni in cui il numero k sia presente nell’array. La procedura riceverà quindi come parametri
    l’array, la sua dimensione logica e il valore k.
*/

#include <stdio.h>
#define DIM 10

void cercaValori(int values[], int len, int k);
int riempiVettori(int values[], int size);

int main() {

    int values[DIM], len, k;
    len = riempiVettori(values, DIM);
    
    printf("Inserire un valore 'k' da cercare nell'array: ");
    scanf("%d", &k);
    printf("\n");

    cercaValori(values, len, k);

    return 0;

}

int riempiVettori(int values[], int size)
{
    int n, len = 0;
    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n != 0 && len < size) {
            values[len] = n;
            len++;
        }

    } while (len < size && n != 0);
    return len;
}

void cercaValori(int values[], int len, int k) {
    for (int i = 0; i < len; i++) {
        if (values[i] == k) {
            printf("%d, ", i);
        }
    }
}