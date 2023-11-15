#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>
#include "myMath.h"

int main() {

    int n, k, i, j;
    k = 1;

    printf("Inserire fino a che livello si vuole visualizzare il triangolo di Tartaglia: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            printf("%d ", coeff_bin(i, j));
        }
        printf("\n");
        k++;
    }

    return 0;

}