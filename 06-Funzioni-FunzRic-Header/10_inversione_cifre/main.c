#define _CRT_SECURE_NO_DEPRECATE

/*
    Si scriva un programma che inverta le cifre di un numero intero N usando una funzione apposita.
    A tal fine, si realizzi sia una versione ricorsiva, sia una versione iterativa della funzione
*/

#include <stdio.h>

int invert(int n);
int pow(int a, int b);
int len(int n);

int main() {

    int n;
    printf("Inserire un intero 'N' di cui invertiro' le cifre: ");
    scanf("%d", &n);

    printf("L'intero invertito a cifre inverse e' %d", invert(n));

    return 0;

}

int invert(int n) {
    if ((0 <= n) && (n < 10)) { // se singola cifra ritorno N
        return n;
    }
    else if (n < 0) { // se numero negativo cambio di segno
        return invert(-n);
    }
    else { // caso normale multi cifra
        int ultimacifra, restodelnumero, z;
        ultimacifra = n % 10;
        restodelnumero = n / 10;
        return ((ultimacifra * pow(10, (len(n)-1))) + invert(restodelnumero));
    }
}

int pow(int a, int b) {
    int prod = 1;

    while (b > 0) {
        prod *= a;
        b--;
    }

    return prod;
}

int len(int n) {
    int lenght;
    if (n == 0) {
        return 1;
    }
    for (lenght = 0; n != 0; lenght++) {
        n /= 10;
    }
    return lenght;
}