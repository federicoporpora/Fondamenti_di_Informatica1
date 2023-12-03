#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 100

typedef struct {
    char nome[31];
    double importo;
} debito;

void load(FILE* fAnagrafe, FILE* fFatture, debito* y, int* N);

int main() {

    debito debitori[DIM];
    int N = 0;
    FILE* fAnagrafe, * fFatture;
    char nome[31];

    fAnagrafe = fopen("anagrafe.txt", "r");
    fFatture = fopen("fatture.txt", "r");

    load(fAnagrafe, fFatture, debitori, &N);

    printf("Inserire il nome dell'utente: ");
    scanf("%s", nome);

    for (int i = 0; i <= N; i++) {
        if (i == N) {
            printf("\nL'utente da lei inserito non ha fatture da pagare.\n");
            break;
        }
        if (strcmp(nome, debitori[i].nome) == 0) {
            printf("\nL'utente %s ha un importo di fatture da pagare di %.2lf EUR.\n", nome, debitori[i].importo);
            break;
        }
    }

    fclose(fAnagrafe);
    fclose(fFatture);

    return 0;

}

void load(FILE* fAnagrafe, FILE* fFatture, debito* y, int* N) {
    int utenteFat, utenteAn, fattN, i, ifEOF;
    double fattIm;
    char status, nome[31], citta[21];

    int found = 0;
    *N = 0;
    while (fscanf(fFatture, "%d %d %lf %c\n", &utenteFat, &fattN, &fattIm, &status) != EOF) { //loop ogni linea di fatture.txt
        if (status == 'p') { // se e' pagata continua
            continue;
        }
        for (i = 0; i < (*N); i++) { // loop per ogni y[i].nome per vedere se e' uguale al nome in anagrafe.txt
            fscanf(fAnagrafe, "%d %s %*s\n", &utenteAn, nome);
            if (utenteAn == utenteFat) {
                found = 1;
                y[i].importo += fattIm;
                break;
            }
        }
        rewind(fAnagrafe);
        if (!found) { // se non e' stato trovato prima il nome in y, questa e la funzione che lo crea
            do {
                if ((ifEOF = fscanf(fAnagrafe, "%d %s %s\n", &utenteAn, nome, &citta)) != EOF && (utenteAn == utenteFat)) {
                    strcpy(y[*N].nome, nome);
                    y[*N].importo = fattIm;
                }
            } while (ifEOF != EOF && (utenteAn != utenteFat));
            (*N)++;
        }
        found = 0;
        rewind(fAnagrafe);
    }
}