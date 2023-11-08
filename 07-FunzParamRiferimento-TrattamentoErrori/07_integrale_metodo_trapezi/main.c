#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "myLib.h"

int main() {

    double a, b;
    double N;

    printf("Inserire i limiti dell'intervallo: ");
    scanf("%lf%lf", &a, &b);
    printf("Inserire in quanti rettangoli suddividere la funzione: ");
    scanf("%lf", &N);

    printf("L'integrale vale circa: %lf", trapezi(a, b, N));

    return 0;

}