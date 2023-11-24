#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

typedef struct Booking {
    char name[1024];
    int seat;
} booking;

int assegna(booking arr[], int dim, int* nPrenotazioni, char name[], int seat) {
    int i;
    for (i = 0; i < (*nPrenotazioni); i++) {
        if (arr[i].seat == seat) {
            return 0;
        }
    }
    if (*nPrenotazioni < dim) {
        strcpy(arr[*nPrenotazioni].name, name);
        arr[*nPrenotazioni].seat = seat;
        (*nPrenotazioni)++;
        return 1;
    }
    return -1;
}

int leggi(booking* dest) {
    char tempName[1024];
    printf("Inserire il nome del cliente (max 1023 caratteri senza spazi): ");
    scanf("%s", &tempName);
    if (strcmp(tempName, "fine") == 0) {
        return -1;
    }
    if (strcmp(tempName, "stampa") == 0) {
        return 0;
    }
    else {
        strcpy((*dest).name, tempName);
        printf("Inserire il numero del posto: ");
        scanf("%d", &(*dest).seat);
    }
    return 1;
}