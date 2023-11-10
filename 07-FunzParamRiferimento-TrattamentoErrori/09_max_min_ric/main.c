#define _CRT_SECURE_NO_DEPRECATE

/*
    Si realizzi due funzioni RICORSIVE che calcolino, rispettivamente, il minimo e il massimo di una sequenza di interi inseriti dall'utente.
    Non è nota a priori la lunghezza della sequenza.
    L'utente segnala il termine della sequenza tramite l'inserimento del valore intero 0 (zero).
    Si implementino poi entrambe le funzioni come una unica procedura ricorsiva che restituisca i risultati tramite parametri passati "per riferimento".
*/

#include <stdio.h>

int maxRic(int a);
int minRic(int a);

int main() {

    int a;

    printf("Serie di numeri max:\nInserire il primo numero: ");
    scanf("%d", &a);
    printf("\nIl numero massimo e' %d\n\n", maxRic(a));
    
    printf("Serie di numeri min:\nInserire il primo numero: ");
    scanf("%d", &a);
    printf("\nIl numero minimo e' %d\n\n", minRic(a));

    return 0;

}

int maxRic(int a) {

    int b;

    printf("Inserire il prossimo numero: ");
    scanf("%d", &b);
    
    if (b == 0) {
        return a;
    }
    else {
        int max;
        max = (a > b) ? a : b;
        return maxRic(max);
    }

}

int minRic(int a) {

    int b;

    printf("Inserire il prossimo numero: ");
    scanf("%d", &b);

    if (b == 0) {
        return a;
    }
    else {
        int min;
        min = (a < b) ? a : b;
        return minRic(min);
    }

}