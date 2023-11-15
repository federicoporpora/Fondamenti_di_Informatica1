#define _CRT_SECURE_NO_DEPRECATE

/*
    Scrivere un programma che, dato un vettore NUM di N interi positivi inseriti dall’utente, ne produca due PAR e DIS contenenti, rispettivamente,
    i numeri pari e dispari del vettore iniziale.
    Si controlli che i numeri inseriti dall’utente siano positivi.
    Per verificare se un numero è pari, si scriva una funzione che restituisca 1 se il numero è pari, 0 altrimenti
    int pari(int n);
*/

#include <stdio.h>
#define N 10

int pari(int n);
void stampaVettori(int vettore[], int len);

int main() {

    int NUM[N], PAR[N], DIS[N], n, i, len = 0, lenDIS = 0, lenPAR = 0;

    do {
        printf("Inserire un intero: ");
        scanf("%d", &n);
        if (len < N && n > 0) {
            NUM[len] = n;
            len++;
        }
    } while (len < N && n != 0);

    for (i = 0; i < len; i++) {
        if (pari(NUM[i]) == 1) {
            PAR[lenPAR] = NUM[i];
            lenPAR++;
        }
        else {
            DIS[lenDIS] = NUM[i];
            lenDIS++;
        }
    }

    stampaVettori(PAR, lenPAR);
    printf("\n");
    stampaVettori(DIS, lenDIS);

    return 0;

}

int pari(int n) { // pari == 1, dispari == 0
    return (n % 2 == 0) ? 1 : 0;
}

void stampaVettori(int vettore[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            printf("%d, ", vettore[i]);
        }
        else {
            printf("%d", vettore[i]);
        }
    }
    printf("]");
}