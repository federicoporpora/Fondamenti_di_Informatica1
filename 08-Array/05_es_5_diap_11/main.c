#define _CRT_SECURE_NO_DEPRECATE

/*
    Si scriva un programma che
    1) richieda all’utente un valore V di soglia;
    2) successivamente prenda in ingresso una sequenza di reali positivi terminata da 0 (massimo 10), e memorizzi in un vettore di float M (di dimensione fisica 10)
    SOLO i valori maggiori di V;
    3) infine crei un secondo vettore MED in cui l’elemento iesimo è calcolato come la media tra l’elemento i-esimo del vettore M e il valore V
*/

#include <stdio.h>
#define DIM 10

void acquisisciValori(int values[], int* len, float V);

int main() {

    int len = 0;
    int i, j;
    float M[DIM], MED[DIM], V;

    printf("Inserire il valore V di soglia: ");
    scanf("%f", &V);

    acquisisciValori(M, &len, V);

    for (i = 0; i < len; i++) {
        MED[i] = (M[i] + V) / 2;
    }

    for (j = 0; j < len; j++) {
        printf("%f, ", MED[j]);
    }

    return 0;

}

void acquisisciValori(float values[], int* len, float V) {
    float n;
    do {
        printf("Inserire un numero: ");
        scanf("%f", &n);
        if (n > V && *len < DIM) {
            values[*len] = n;
            (*len)++;
        }
    } while (n != 0 && *len < DIM);
}