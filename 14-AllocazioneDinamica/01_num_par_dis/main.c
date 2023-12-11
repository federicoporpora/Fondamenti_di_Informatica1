#define _CRT_SECURE_NO_DEPRECATE

// SONO IL REEEEEE IL REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

#include <stdio.h>
#include <stdlib.h>

int readLength(FILE* f, int* even, int* odd);
void myStampaVettori(int arr[], int len);

int main() {

    int puppa, *arr;
    FILE* f;
    char request;

    if ((f = fopen("valori.dat", "wb")) == NULL) {
        printf("Il file non e' stato aperto correttamente.");
        exit(1);
    }

    do {
        printf("Inserire un intero: ");
        scanf("%d", &puppa);
        fwrite(&puppa, sizeof(int), 1, f);
        printf("Continuare? (s/n) ");
        scanf("%*c");
        scanf("%c", &request);
    } while (request == 's');

    fclose(f);

    if ((f = fopen("valori.dat", "rb")) == NULL) {
        printf("Il file non e' stato aperto correttamente.");
        exit(2);
    }

    int even, odd, len;

    even = odd = len = 0;

    len = readLength(f, &even, &odd);
    rewind(f);
    
    arr = (int*)malloc(sizeof(int) * len);

    int i = 0;
    while (fread(&puppa, sizeof(int), 1, f) == 1) {
        if (puppa % 2 == 0) {
            arr[i] = puppa;
            i++;
        }
    }
    rewind(f);
    while (fread(&puppa, sizeof(int), 1, f) == 1) {
        if (puppa % 2 == 1) {
            arr[i] = puppa;
            i++;
        }
    }

    myStampaVettori(arr, len);

    free(arr);
    fclose(f);

    return 0;

}

int readLength(FILE* f, int* even, int* odd) {
    int num;
    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (num % 2 == 0) {
            (*even)++;
        }
        else {
            (*odd)++;
        }
    }
    return (*even) + (*odd);
}

void myStampaVettori(int arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            printf("%d, ", arr[i]);
        }
        else {
            printf("%d", arr[i]);
        }
    }
    printf("]");
}