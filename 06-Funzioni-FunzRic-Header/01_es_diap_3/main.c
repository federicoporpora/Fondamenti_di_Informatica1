#define _CRT_SECURE_NO_DEPRECATE

/*
    Codificare in C la funzione "int mioMax(int x, int y)" che restituisca il massimo valore tra due interi.
    Codificare in C la funzione "int max3(int x, int y, int z)" che restituisca il massimo valore fra tre interi, sfruttando la funzione miomax definita precedentemente.
    Definire un possibile main che prenda in ingresso i tre valori dall'utente e ne stampi il massimo.
*/

#include <stdio.h>

int mioMax(int x, int y);
int mioMax3(int x, int y, int z);

int main() {

    int a, b, c, max;

    printf("Inserire tre valori interi di cui vuoi sapere il massimo: ");
    scanf("%d%d%d", &a, &b, &c);

    max = mioMax3(a, b, c);

    printf("\nL'intero maggiore inserito e' %d\n", max);

    return 0;

}

int mioMax(int x, int y) {

    int max;
    max = (x >= y) ? x : y;

    return max;

}

int mioMax3(int x, int y, int z) {

    int max;
    max = mioMax(x, y);
    max = mioMax(max, z);

    return max;

}