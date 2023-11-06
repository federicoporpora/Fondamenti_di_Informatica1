#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>

int main() {

    printf("%d", divide(50, 5));

    return 0;

}

int divide(int dividend, int divisor) {
    int abs_dividend, abs_divisor, i, sum;
    abs_dividend = abs(dividend);
    abs_divisor = abs(divisor);
    i = 0;
    sum = 0;
    while (sum < dividend) {
        sum += divisor;
        i++;
    }
    return i;
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    else {
        return a;
    }
}