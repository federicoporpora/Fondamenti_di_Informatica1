#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>

int main() {

    int caratteri = 0, parole = 1, righe = 1;

    FILE* fp;

    char temp;

    if ((fp = fopen("parole.txt", "r")) == NULL) {
        printf("Il file non e' stato aperto correttamante");
        exit(-1);
    }

    while (fscanf(fp, "%c", &temp) != EOF) {
        if (temp == '\n') {
            righe++;
            parole++;
            caratteri--;
        }
        if (temp == ' ') {
            parole++;
        }
        else {
            caratteri++;
        }
    }

    printf("Caratteri: %d\tParole: %d\tRighe: %d\n", caratteri, parole, righe);

    fclose(fp);

    return 0;

}