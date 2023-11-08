#define _CRT_SECURE_NO_DEPRECATE

/*
    Realizzare una funzione che, date le lunghezze dei tre lati di un triangolo restituisca uno fra tre codici:
        PRIMO CASO: triangolo non valido
            – Un triangolo è invalido se uno dei tre lati è più lungo della somma degli altri due, oppure se uno dei tre lati è negativo
        SECONDO CASO: triangolo degenere
            – Un triangolo è degenere se uno dei tre lati è nullo, oppure uno dei tre lati è uguale alla somma degli altri due
        TERZO CASO: triangolo valido
            – Nel caso di triangolo valido
                La funzione deve anche restituire il perimetro e l’area del triangolo
                Per l’area, si utilizzi la formula (con s semiperimetro) A = sqrt(s(s-a)(s-b)(s-c))
    Realizzare una procedura per la gestione del risultato
*/

#include <stdio.h>
#include "myLib.h"

int main() {

    double a, b, c, area, perimetro;
    area = perimetro = 0;

    do {
        printf("Inserire i lati del triangolo: ");
        scanf("%lf%lf%lf", &a, &b, &c);
        switch (area_e_perimetro_triangolo(a, b, c, &area, &perimetro)) {
        case 1:
            printf("Il triangolo non e' valido, riprova\n\n");
            break;
        case 2:
            printf("Il triangolo e' degenere, riprova\n\n");
            break;
        default:
            printf("Perimetro: %lf\tArea: %lf\n", perimetro, area);
            break;
        }
    } while (area_e_perimetro_triangolo(a, b, c, &area, &perimetro) != 0);
    
    return 0;

}