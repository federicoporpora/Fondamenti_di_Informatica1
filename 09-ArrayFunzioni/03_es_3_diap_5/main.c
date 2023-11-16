#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input due sequenze di interi, di lunghezza non nota a priori (al più 10), e terminate da 0.
    A tal scopo, si realizzi una apposita funzione.
    Si realizzi un main che invochi le funzioni, e che stampi a video tutti gli elementi del primo vettore che compaiono nel secondo vettore nella
    stessa posizione (cioè con lo stesso indice).
*/

#include <stdio.h>
#define DIM 10

int myMin(int a, int b);
int riempiVettori(int values[], int size);

int main() {

    int values1[DIM], values2[DIM], len1, len2, lenMin, i;

    len1 = riempiVettori(values1, DIM);
    len2 = riempiVettori(values2, DIM);

    lenMin = myMin(len1, len2);

    for (i = 0; i < lenMin; i++) {
        if (values1[i] == values2[i]) {
            printf("%d, ", values1[i]);
        }
    }

    return 0;

}

int riempiVettori(int values[], int dim)
{
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

int myMin(int a, int b) {
    return (a < b) ? a : b;
}