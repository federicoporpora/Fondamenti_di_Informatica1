#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>
#include "myLib.h"

int main() {

    double r1, i1, r2, i2, rSum, iSum;
    rSum = iSum = 0;

    printf("Inserire il primo numero complesso: ");
    scanf("%lf%lfi", &r1, &i1);
    printf("Inserire il secondo numero complesso: ");
    scanf("%lf%lfi", &r2, &i2);
    sommaComplessi(r1, i1, r2, i2, &rSum, &iSum);

    printf("La somma dei due numeri complessi e' %lf %lf", rSum, iSum);

    return 0;

}