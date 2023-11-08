#include <math.h>

int secondoGrado(double a, double b, double c, double* sol1, double* sol2) {
    if (pow(b, 2) - 4 * a * c < 0) {
        return 1;
    }
    else if (pow(b, 2) - 4 * a * c == 0) {
        *sol1 = -b / (2 * a);
        return 2;
    }
    else if (a == 0) {
        *sol1 = (-c) / b;
        return 3;
    }
    else {
        *sol1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        *sol2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        return 0;
    }
}