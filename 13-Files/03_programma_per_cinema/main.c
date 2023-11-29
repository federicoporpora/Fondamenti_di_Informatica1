#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char titolo[31];
    float prezzo;
} film;

void load(FILE* fSale, FILE* fProg, film* y, int* N);

int main() {

    FILE *fSale, *fProg;
    int N = 0, i;
    film prezzi[100];

    if ((fSale = fopen("sale.txt", "r")) == NULL) { //controllo apertura file sale.txt
        printf("Il file sale.txt non si e' aperto");
        exit(1);
    }

    if ((fProg = fopen("cineprogramma.txt", "r")) == NULL) { //controllo apertura file cineprogramma.txt
        printf("Il file cineprogramma.txt non si e' aperto");
        exit(1);
    }

    load(fSale, fProg, prezzi, &N);

    float media = 0;

    for (i = 0; i < N; i++) {
        media += prezzi[i].prezzo;
    }

    media /= N;

    puts("Elenco dei film con il costo del biglietto sotto la media:");

    for (i = 0; i < N; i++) {
        if (prezzi[i].prezzo < media) {
            printf("Titolo: %-30s\tPrezzo: %.2f\n", prezzi[i].titolo, prezzi[i].prezzo);
        }
    }

    fclose(fSale);
    fclose(fProg);

    return 0;

}


void load(FILE* fSale, FILE* fProg, film* y, int* N) {
    char salaP[21], salaS[21], titolo[31];
    float prezzo;
    *N = 0;
    while (fscanf(fProg, "%s %s %*d-%*d-%*d\n", titolo, salaP) != EOF && *N < 100) {
        strcpy(y[*N].titolo, titolo);
        rewind(fSale);
        while (fscanf(fSale, "%s %f\n", salaS, &prezzo) != EOF) {
            if (strcmp(salaP, salaS) == 0) {
                y[*N].prezzo = prezzo;
                break;
            }
        }
        (*N)++;
    }
}