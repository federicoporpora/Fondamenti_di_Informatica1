#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "myMath.h"

int main() {

    int mcm_current;

    printf("Inserire il primo valore: ");
    scanf("%d", &mcm_current);
    while (mcm_current <= 100) {
        int n;
        printf("Inserire un altro valore valore: ");
        scanf("%d", &n);
        mcm_current = mcm(mcm_current, n);
        printf("\nL'mcm corrente e' %d\n\n", mcm_current);
    }

    return 0;

}