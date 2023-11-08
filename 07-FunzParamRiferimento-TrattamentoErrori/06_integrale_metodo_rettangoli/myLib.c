#include <math.h>

double funzione(double x) {
    return pow(sin(x), 2);
}

double rettangoli(double a, double b, double N) {
    double base = (b - a) / N;
    double integrale = 0;
    for (double i = 1; i <= N; i++) {
        integrale += base * (funzione(a + (base * i)));
    }
    return integrale;
}