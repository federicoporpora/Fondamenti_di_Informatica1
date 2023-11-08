#include <math.h>

int area_e_perimetro_triangolo(double a, double b, double c, double* area, double* perimetro) {
    if ((a == b + c) || (b == a + c) || (c == a + b) || (a == 0) || (b == 0) || (c == 0)) {    //triangolo degenere
        return 2;
    }
    else if ((a > b + c) || (b > a + c) || (c > a + b) || (a < 0) || (b < 0) || (c < 0)) {   //triangolo non valido
        return 1;
    }
    else {  //triangolo valido
        *perimetro = a + b + c;
        double s = *perimetro / 2;
        *area = sqrt(s * (s - a) * (s - b) * (s - c));
        return 0;
    }
}