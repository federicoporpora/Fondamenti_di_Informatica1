#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DIM 65

typedef struct {
    int cd_code;
    char renter[DIM];int days;
} Rent;

int readRented(char nomeFile[], char nomeUtente[], Rent* V, int dim);

int main() {

    char renter[DIM];
    int dim;

    printf("Inserire il nome di un cliente: ");
    scanf("%s", renter);
    printf("Inserire il numero di elementi su cui si vuole fare la statistica: ");
    scanf("%d", &dim);
    printf("\n");

    Rent* V;

    V = (Rent*)malloc(dim * sizeof(Rent));

    int logicDim;

    logicDim = readRented("RentedLog.txt", renter, V, dim);

    double media = 0;

    for (int i = 0; i < logicDim; i++) {
        printf("Nome cliente: %s\tCodice: %d\tGiorni: %d\n", V[i].renter, V[i].cd_code, V[i].days);
        media += V[i].days;
    }

    printf("\nLa media dei giorni di noleggio e' di %.2lf giorni\n\n", media / logicDim);

    free(V);

    return 0;

}

int readRented(char nomeFile[], char nomeUtente[], Rent* V, int dim) {
    FILE* f;
    if ((f = fopen(nomeFile, "r")) == NULL) {
        printf("Il file non e' stato aperto correttamente in lettura.");
        exit(1);
    }
    int i = 0;
    Rent temp;
    while (fscanf(f, "%d %s %d\n", &temp.cd_code, temp.renter, &temp.days) != EOF && i < dim) {
        if (strcmp(temp.renter, nomeUtente) == 0) {
            V[i].cd_code = temp.cd_code;
            V[i].days = temp.days;
            strcpy(V[i].renter, temp.renter);
            i++;
        }
    }
    fclose(f);
    return i;
}