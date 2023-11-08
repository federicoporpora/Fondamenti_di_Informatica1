#include <math.h>

double f(double x) {
    return sin(x);
}

double trapezi(double a, double b, double N) {
    double base = (b - a) / N;
    double integrale = 0;
    for (double i = 0; i < N; i++) {
        integrale += ((f(a + (base * i)) + f(a + (base * (i + 1)))) * base) / 2;
    }
    return integrale;
}