#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>
#include "myLib.h"

int main() {

    float re, im, modulo, argomento;
    modulo = argomento = 0;

    printf("Inserire la parte reale del numero complesso: ");
    scanf("%f", &re);
    printf("Inserire la parte immaginaria del numero complesso: ");
    scanf("%f", &im);

    while (converti_complex(re, im, &modulo, &argomento) == 0) {
        printf("Il numero reale inserito e' == 0, non e' possibile dividere per 0, riprova\n");
        printf("Inserire la parte reale del numero complesso: ");
        scanf("%f", &re);
        printf("Inserire la parte immaginaria del numero complesso: ");
        scanf("%f", &im);
    }
    printf("Modulo del numero complesso: %f\nArgomento del numero complesso: %f", modulo, argomento);

    return 0;

}