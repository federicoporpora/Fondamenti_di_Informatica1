#include <math.h>

int converti_complex(float re, float im, float* modulo, float* argomento) {
    *modulo = sqrt(pow(re, 2) + pow(im, 2));
    if (re != 0) {
        *argomento = atan2(im, re);
        return 1;
    }
    else {
        return 0;
    }
}