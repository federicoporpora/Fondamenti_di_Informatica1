#define _CRT_SECURE_NO_DEPRECATE

/*
    Si vogliono elaborare alcuni dati metereologici, riguardanti alcune località sciistiche. Per ogni località, un utente inserisce il codice della località e i cm
    di manto nevoso (entrambi interi). Il codice 0, inserito come località, indica che l’utente non vuole inserire altri dati.
    Il programma deve memorizzare tali dati in due appositi vettori (uno per le località ed uno per la neve caduta)
    Il programma deve poi stampare a video i codici di tutte le località che risultino avere un manto nevoso inferiore alla media, calcolata sui valori inseriti
*/

#include <stdio.h>
#define DIM 10
void stampaVettori(int vettore[], int len);

int main() {

    int loc[DIM], cm[DIM], codice, len = 0, cmNeve, i;
    double mediacm = 0;

    do {
        printf("Inserire il codice della citta': ");
        scanf("%d", &codice);
        if (len < DIM && codice != 0) {
            printf("Inseire i cm di neve: ");
            scanf("%d", &cmNeve);
            if (cmNeve < 0) {
                printf("La quantita' di neve inserita e' negativa, riprova\n");
            }
            else {
                loc[len] = codice;
                cm[len] = cmNeve;
                len++;
            }
        }
    } while (len < DIM && codice != 0);

    for (i = 0; i < len; i++) {
        mediacm += cm[i];
    }

    mediacm /= (len);

    for (i = 0; i < len; i++) {
        if (cm[i] < mediacm) {
            printf("%d, ", loc[i]);
        }
    }

    return 0;

}

void stampaVettori(int vettore[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            printf("%d, ", vettore[i]);
        }
        else {
            printf("%d", vettore[i]);
        }
    }
    printf("]");
}