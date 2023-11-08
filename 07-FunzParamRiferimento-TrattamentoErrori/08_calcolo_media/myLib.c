#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

double mediaRic(double sum, int n) {
    double num;
    printf("Inserire il %do numero: ", n + 1);
    scanf("%lf", &num);
    if (num == 0) {
        return (sum / n);
    }
    else {
        return mediaRic((sum + num), (n + 1));
    }
}