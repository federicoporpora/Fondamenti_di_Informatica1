#define _CRT_SECURE_NO_DEPRECATE

/*
    Codice segreto nella pagina di un libro
    Sono date due stringhe, una denominata msg e una denominata secret (non più lunga di msg) di caratteri tutti
    minuscoli
    Si vuole sapere se tutti i caratteri di secret sono contenuti nello stesso ordine (ma eventualmente
    intervallati da altri caratteri) nella stringa msg
    In caso positivo, il programma deve restituire una copia del msg originale, dove però ad ogni lettera
    riconosciuta come facente parte di secret viene sostituita la lettera maiuscola
    Es: msg = “ma che bel castello”, secret = “cestello”
    Risultato: SI e stringa “ma ChE bel caSTELLO”
*/

#include <stdio.h>
#include <string.h>
#define DIM 50
#define SI 1
#define NO 0

int findSecret(char msg[], char secret[]);

int main() {

    char msg[DIM], secret[DIM];

    printf("Inserire la stringa in cui e' contenuto il messaggio segreto: (max %d caratteri e senza spazi) ", DIM);
    scanf("%s", &msg);
    printf("Inserire la stringa segreta: ");
    scanf("%s", &secret);

    if (findSecret(msg, secret) == SI) {
        printf("%s", msg);
    }
    else {
        printf("Non e' presente del tutto ed in fila la stringa nel messaggio.");
    }

    return 0;

}

int findSecret(char msg[], char secret[]) {
    int i, j, firstChar = 0;
    int dimMsg = strlen(msg);
    int dimSecret = strlen(secret);
    for (i = 0; i < dimSecret; i++) {
        for (j = 0; j <= dimMsg; j++) {
            if (msg[j] == secret[i] && j > firstChar) {
                msg[j] = secret[i] - 32;
                firstChar = j;
                break;
            } else if (j == dimMsg) {
                return NO;
            }
        }
    }
    return SI;
}