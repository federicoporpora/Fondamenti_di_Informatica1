#define _CRT_SECURE_NO_DEPRECATE

/*
    Il candidato realizzi una funzione ricorsiva secondoGrado(...) che ricevuto in ingresso tre valori interi a, b, c, coefficienti del polinomio:
    ax2 + bx + c = 0
    restituisca (tramite parametri passati per riferimento) le radici del polinomio.
    Tramite il valore di ritorno, la funzione restituisca eventuali codici di errore o di successo.
*/

#include <stdio.h>
#include "myLib.h"

int main() {

    double a, b, c, sol1, sol2;
    sol1 = sol2 = 0;
    int x;

    printf("Inserire i coefficienti dell'equazione di secondo grado: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    x = secondoGrado(a, b, c, &sol1, &sol2);

    if (x == 1) {
        printf("No radici reali, pow(b, 2) - 4 * a * c < 0");
    }
    else if (x == 2) {
        printf("Due radici coincidenti: %lf", sol1);
    }
    else if (x == 3) {
        printf("Equazione di primo grado, soluzione:\t%lf", sol1);
    }
    else {
        printf("Radici:\t%lf\t%lf", sol1, sol2);
    }

    printf("\n");

    return 0;
    
}