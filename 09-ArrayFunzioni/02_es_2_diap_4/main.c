#define _CRT_SECURE_NO_DEPRECATE

/*
    Realizzare una funzione che riceva in ingresso un array di interi e la sua dimensione, un elemento da cercare ed un intero passato per riferimento.
    La funzione deve restituire un valore interpretabile come “vero” se l’elemento è presente nell’array. Inoltre, tramite l’intero passato per riferimento, la funzione deve
    restituire anche la posizione dell’elemento nell’array
    Realizzare anche un main di esempio
*/

#include <stdio.h>
#define DIM 10

int trovaInt(int values[], int len, int incognita, int* index);

int main() {

    int n, len = 0, values[DIM], i = 0, x;

    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        values[len] = n;
        len++;
    } while (len < DIM);

    printf("Inserire il numero da ricercare: ");
    scanf("%d", &x);

    printf("%d, %d", trovaInt(values, len, x, &i), i);

    return 0;

}

int trovaInt(int values[], int len, int incognita, int* index) {
    for (*index = 0; *index < len; (*index)++) {
        if (values[*index] == incognita) {
            return 1;
        }
        else if (*index == len - 1) {
            *index = -1;    // se non e' presente l'intero ritorno come indice -1, che e' esterno al dominio dell'array
            return 0;
        }
    }
}