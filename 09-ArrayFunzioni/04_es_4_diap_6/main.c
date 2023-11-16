#define _CRT_SECURE_NO_DEPRECATE

/*
    Realizzare una procedura che, ricevuti in ingresso un vettore di interi e la sua dimensione, e due interi passati per riferimento
    di nome “pari” e “dispari”, restituisca il numero di interi pari e di interi dispari presenti nell’array.
    Si realizzi un main che, utilizzando una appropriata funzione, legga dall’utente una sequenza di al più 10 numeri (eventualmente terminati da zero),
    e utilizzando la procedura di cui al punto precedente, stampi a video quanti numeri pari e dispari sono stati inseriti.
*/

#include <stdio.h>
#define DIM 10

void PariDispari(int values[], int dim, int* pari, int* dispari);

int main() {

    int len, values[DIM], pari = 0, dispari = 0;

    len = riempiVettori(values, DIM);

    PariDispari(values, len, &pari, &dispari);

    printf("\nInteri pari: %d\tInteri dispari: %d", pari, dispari);

    return 0;

}

void PariDispari(int values[], int len, int* pari, int* dispari) {
    for (int i = 0; i < len; i++) {
        if (values[i] % 2 == 0) {
            *pari += 1;
        }
        else {
            *dispari += 1;
        }
    }
}

int riempiVettori(int values[], int dim) {
    int n, len = 0;
    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n != 0 && len < dim) {
            values[len] = n;
            len++;
        }

    } while (len < dim && n != 0);
    return len;
}