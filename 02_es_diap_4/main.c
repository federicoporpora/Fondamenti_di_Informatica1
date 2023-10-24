#define _CRT_SECURE_NO_DEPRECATE

/*
    Si scriva una funzione "int somma2(int n);" che dato n deve calcolare "doppia sommatoria da i = 1 ad n e da j = 1 ad i di j)
    A tal fine si sfrutti una funzione int somma(int n);
*/

#include <stdio.h>

int somma(int n);
int somma2(int n);

int somma(int i) {

    int j, sum;
    sum = 0;

    for (j = 1; j <= i; j++) {
        sum += j;
    }

    return sum;

}

int somma2(int n) {

    int i, sum;
    sum = 0;

    for (i = 1; i <= n; i++) {
        sum += somma(i);
    }

    return sum;

}

int main() {

    int n, sum;

    printf("Inserire il limite \"n\" della sommatoria: ");
    scanf("%d", &n);

    sum = somma2(n);

    printf("Il risultato della sommatoria e' %d\n", sum);
}