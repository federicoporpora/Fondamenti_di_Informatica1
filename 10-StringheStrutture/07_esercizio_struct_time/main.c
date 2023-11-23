#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "tempo.h"
#define DIM 10

int main() {

    Time v[DIM];
    int lenV;

    lenV = leggiMoreTimes(v, DIM);

    v[2] = subtract(v[0], v[1]);

    printf("%d:%.2d:%.2d", v[2].hour, v[2].minute, v[2].second);

    return 0;

}