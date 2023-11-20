#define _CRT_SECURE_NO_DEPRECATE

/*
	Creare un programma che legga da input una sequenza di interi, di lunghezza non nota a priori
	(al più 10), e terminata da 0. A tal scopo, si realizzi una apposita funzione.
	Si realizzi una funzione che, ricevuti un array e la sua dimensione, ed un elemento da cercare,
	restituisca il valore -1 se l’elemento non è presente nell’array; altrimenti restituisca il
	primo indice in cui è presente l’elemento cercato.
	Si realizzi un main che invoca le funzioni, e che stampi a video tutti gli elementi del
	vettore che compaiono solo ed esattamente 2 volte nel vettore
*/

#include <stdio.h>
#define DIM 10

int myRiempiVettori(int arr[], int dim);
int myRicercaValori(int arr[], int len, int x);

int main() {

    int arr[DIM], len, i, j, count;

    len = myRiempiVettori(arr, DIM);

    for (i = 0; i < len; i++) {
        count = 0;
        for (j = 0; j < len; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 2) {
            int primoIndice = myRicercaValori(arr, len, arr[i]);
            if (primoIndice == i) {
                printf("%d ", arr[i]);
            }
        }
    }
    printf("\n");

    return 0;
}

int myRiempiVettori(int arr[], int dim) {
    int n, len = 0;
    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n != 0 && len < dim) {
            arr[len] = n;
            len++;
        }

    } while (len < dim && n != 0);
    return len;
}

int myRicercaValori(int arr[], int len, int x) {
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}