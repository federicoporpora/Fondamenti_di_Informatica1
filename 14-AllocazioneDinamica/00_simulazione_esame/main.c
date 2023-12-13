#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myLib.h"

typedef struct {
    int viaggio;
    char descr[1024];
    float importo;
} spesa;

typedef struct {
    int viaggio;
    spesa arr[];
    int dim;
} rimborso;

void scriviSpese(char* nomeFile);

int main() {



}

void scriviSpese(char* nomeFile) {
    int matricola;
    printf("Inserire il proprio numero di matricola: ");
    scanf("%s", &matricola);

    FILE* f;
    strcpy(nomeFile, matricola);
    strcat(nomeFile, ".txt");

    f = fopen(nomeFile, "w");

    if (f == NULL) {
        printf("Il file non e' stato aperto correttamente in scrittura.");
        exit(1);
    }

    int viaggio;
    char descr[1024];
    float importo;

    do {
        printf("Inserire il numero di viaggio: ");
        scanf("%d", &viaggio);

        if (viaggio != -1) {
            printf("Inserire la descrizione della spesa: ");
            scanf("%s", descr);

            printf("Inserire l'importo della spesa: ");
            scanf("%f", &importo);

            fprintf(f, "%d %s %f\n", viaggio, descr, importo);
        }
    } while (viaggio != -1);


    fclose(f);

    return 0;
}

spesa* leggiSpese(char* nomeFile, int* dim) {
    FILE* f;
    f = fopen(nomeFile, "r");
    if (f == NULL) {
        printf("Il file non e' stato aperto correttamente in lettura.");
        exit(2);
    }

    int viaggio, nRighe;
    char descr[1024];
    float importo;

    while (fscanf(f, "%d %s %f\n", &viaggio, descr, &importo) != EOF) {
        nRighe++;
    }
    rewind(f);

    spesa* arr;
    arr = (spesa*)malloc(nRighe * sizeof(spesa));
    int i = 0;

    while (fscanf(f, "%d %s %f\n", &viaggio, descr, &importo) != EOF) {
        arr[i].viaggio = viaggio;
        strcpy(arr[i].descr, descr);
        arr[i].importo = importo;
        i++;
    }
    return &arr[0];
}

void merge(int v[], int i1, int i2, int fine, int vout[]) {
    int i = i1, j = i2, k = i1;
    while (i <= i2 - 1 && j <= fine) {
        if (v[i] < v[j])
            vout[k] = v[i++];
        else
            vout[k] = v[j++];
        k++;
    }
    while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
    while (j <= fine) { vout[k] = v[j++]; k++; }
    for (i = i1; i <= fine; i++) v[i] = vout[i];
}

void mergeSort(int v[], int first, int last,
    int vout[]) {
    int mid;
    if (first < last) {
        mid = (last + first) / 2;
        mergeSort(v, first, mid, vout);
        mergeSort(v, mid + 1, last, vout);
        merge(v, first, mid + 1, last, vout);
    }
}