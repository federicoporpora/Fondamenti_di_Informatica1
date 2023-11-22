#define _CRT_SECURE_NO_DEPRECATE

/*
    Si vuole implementare un programma per il calcolo dell’inflazione su determinati prodotti commerciali.
    A tal scopo ogni prodotto è rappresentato tramite una struttura item, definita da una stringa name con il
    nome del prodotto, e da due float old_price e new_price rappresentanti i prezzi.

     Si scriva una funzione lettura() che riceva come parametri di ingresso un vettore prezzi di
     strutture item, la dimensione fisica max del vettore prezzi, e un puntatore a intero num che
     rappresenta la dimensione logica del vettore. La funzione deve leggere da standard input il nome
     del prodotto ed i due prezzi, e deve copiare tale informazione nella prima posizione libera nel vettore prezzi.

     La funzione deve terminare se l’utente inserisce come nome del prodotto il termine “fine”, oppure se
     viene raggiunta la dimensione fisica del vettore. La dimensione logica del vettore prezzi così riempito
     deve essere restituita tramite il parametro num(passato appunto per riferimento). Al termine della
     lettura dei dati la funzione deve restituire il valore 0.

     Si scriva un programma main che, dopo aver definito un vettore di strutture item (di dimensione massima MAX_ITEM),
     invochi la funzione lettura() per riempire tale vettore. Il programma stampi poi a video nome e tasso
     d’inflazione per ogni prodotto, utilizzando la formula: infl == ((new_price / old-price) - 1) * 100
*/

#include <stdio.h>
#include <string.h>
#define DIM 21
#define FINE 1
#define MAX_ITEM 20

typedef struct {
    char name[DIM];
    float old_price, new_price;
} item;

int lettura(item prezzi[], int dim, int* num);

int main() {

    item prezzi[MAX_ITEM];
    int num, i;

    lettura(prezzi, MAX_ITEM, &num);

    for (i = 0; i < num; i++) {
        printf("Nome del prodotto: %s\tTasso d'inflazione: %f\n\n", prezzi[i].name, (((prezzi[i].new_price / prezzi[i].old_price) - 1) * 100));
    }

    return 0;

}

int lettura(item prezzi[], int dim, int* num) {
    (*num) = 0;
    float n;
    char str[DIM];
    do {
        printf("Inserire il nome del prodotto: (per terminare scrivere 'fine') ");
        scanf("%s", &str);
        if (verificaFine(str) != FINE && (*num) < dim) {
            strcpy(prezzi[*num].name, str);
            printf("Inserire il vecchio prezzo: ");
            scanf("%f", &n);
            prezzi[*num].old_price = n;
            printf("Inserire il nuovo prezzo: ");
            scanf("%f", &n);
            prezzi[*num].new_price = n;
            (*num)++;
        }
        printf("\n");
    } while (verificaFine(str) != FINE && (*num) < dim);
    return 0;
}

int verificaFine(char str[]) {
    int i;
    char fine[5] = "fine";
    if (strlen(str) != 4) {
        return 0;
    }
    else {
        for (i = 0; i < 4; i++) {
            if (str[i] != fine[i]) {
                return 0;
            }
        }
        return 1;
    }
}