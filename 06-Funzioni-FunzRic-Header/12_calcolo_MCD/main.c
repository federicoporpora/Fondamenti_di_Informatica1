#define _CRT_SECURE_NO_DEPRECATE

/*
    Si scriva una programma che legga da input due numeri e ne determini il Massimo Comun Divisore (MCD), tramite una funzione implementata ricorsivamente.
    Per calcolare MCD, si usi l’algoritmo di Euclide:
    MCD(m, n) = m se m==n
    MCD(m, n) = MCD(m-n, n) se m>n
    MCD(m, n) = MCD(m, n-m) se n>m
*/

#include <stdio.h>

int MCD(int m, int n);

int main() {

    int m, n;

    printf("Inserire due numeri di cu calcolero' il massimo comune divisore: ");
    scanf("%d%d", &m, &n);

    printf("\nIl massimo comune divisore di %d e %d e' %d\n", m, n, MCD(m, n));

    return 0;

}

int MCD(int m, int n) {
    if (m == n) {
        return m;
    }
    else if (m > n) {
        MCD(m - n, n);
    }
    else {
        MCD(m, n - m);
    }
}