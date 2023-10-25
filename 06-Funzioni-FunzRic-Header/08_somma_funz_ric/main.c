#define _CRT_SECURE_NO_DEPRECATE

/*
    Scrivere una funzione ricorsiva "int ric(int x)" che calcoli, ricorsivamente, la somma di tutti i numeri compresi tra 0 ed x.
*/

#include <stdio.h>

int ric(int x);

int main() {

    printf("%d", ric(8));

    return 0;

}

int ric(int x) {
    if (x == 0) {
        return 0;
    }
    else {
        return (x + ric(x - 1));
    }
}