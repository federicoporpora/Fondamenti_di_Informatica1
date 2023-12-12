#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DIM 32

typedef struct {
    char name[DIM];
    int points;
} User;

int main() {

    //PRIMA FASE CHE E' L'AGGIUNTA DI DATI AL FILE "punti.dat"

    FILE* f;

    if ((f = fopen("punti.dat", "wb")) == NULL) {
        printf("Il file non e' stato aperto correttamente per la scrittura.");
        exit(1);
    }

    char name[DIM];
    int points, i;
    User temp;
    printf("\t- - - FASE DI INSERIMENTO - - -\n");
    i = 0;
    do {
        printf("Inserire il nome: ");
        scanf("%s", name);
        printf("Inserire i punti: ");
        scanf("%d", &points);
        printf("\n");
        if (points != -1) {
            strcpy(temp.name, name);
            temp.points = points;
            fwrite(&temp, sizeof(User), 1, f);
            i++;
        }
    } while (points != -1);

    fclose(f);    

    //SECONDA FASE CHE E' L'ESERCIZIO DI PER SE

    printf("\n\n\t- - - ESERCIZIO VERO E PROPRIO - - -\n");

    int n;
    //printf("\n\nInserire il numero di clienti salvati: ");
    //scanf("%d", &n);
    //so gia il numero di utenti inseriti dato che ho aggiunto personalmente la prima parte
    //del codice per semplificare il programma
    n = i;

    User* V;

    V = (User*)malloc(n * sizeof(User));

    int min;
    printf("Inserire il minimo punteggio: ");
    scanf("%d", &min);

    readPoints("punti.dat", V, n, min);
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (V[i].name[0] == 'M' && V[i].name[1] == 'e') {
            printf("Nome: %s \tPunteggio: %d\n", V[i].name, V[i].points);
        }
    }
    printf("\n");

    free(V);

    return 0;

}

int readPoints(char usersFile[], User results[], int maxDim, int minPoints) {
    FILE* f;
    int i = 0;
    if ((f = fopen(usersFile, "rb")) == NULL) {
        return -1;
    }

    while (i < maxDim && fread(&results[i], sizeof(User), 1, f) > 0) {
        if (results[i].points >= minPoints) {
            i++;
        }
    }
    fclose(f);
    return i;
}