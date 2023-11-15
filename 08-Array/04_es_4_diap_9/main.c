#define _CRT_SECURE_NO_DEPRECATE

/*
    Realizzare un programma che legga da input una sequenza di interi positivi, terminati da 0.
    Tali numeri devono essere memorizzati in un array (di dimensione massima 10).
    Il programma quindi provveda a stampare a video tutti i numeri pari che sono memorizzati nell’array in una posizione con indice pari.
    
    Estensione: si abbia cura di verificare che siano immessi numeri fino al limite di 10 elementi; dopo tale limite, il programma stampi un messaggio di errore,
    finchè la sequenza non sarà terminata da 0.
    
    Estensione: riprogettare il programma spostando la fase di acquisizione dei dati e l’algoritmo di stampa in due funzioni apposite.
*/

#include <stdio.h>
#define DIM 10

void acquisisciValori(int values[], int* len);

int main() {

    int len = 0;
    int i, values[DIM];

    acquisisciValori(values, &len);

    for (i = 0; i < len; (i += 2)) {;
        if (values[i] % 2 == 0) {
            printf("%d ", values[i]);
        }
    }

    return 0;

}

void acquisisciValori(int values[], int* len) {
    int n;
    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n > 0 && *len < DIM) {
            values[*len] = n;
            (*len)++;
        }
    } while (n > 0 && *len < DIM);
}