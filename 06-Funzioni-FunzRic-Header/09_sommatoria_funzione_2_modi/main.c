#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>

double f(double a, int n);

int main() {

    double a;
    int n;

    printf("Inserire la base 'a' ed il limite 'n' della sommatoria: ");
    scanf("%lf%d", &a, &n);

    printf("Il risultato della sommatoria e' %lf\n", f(a, n));

    return 0;

}

double f(double a, int n) {
    if (n != 0) {
        return (a - (n / a)) + f(a, n - 1);
    }
    else {
        return 0;
    }
}