#define _CRT_SECURE_NO_DEPRECATE

/*
    Il candidato realizzi una procedura ricorsiva convertiBin(...) che ricevuto in ingresso un valore intero positivo, stampi a video la sua rappresentazione in binario.
    Si presti particolare attenzione all'ordine di stampa dei valori binari: i bit meno significativi devono ovviamente essere a destra.
*/

#include <stdio.h>

void convertiBin(int bin);

int main() {

    convertiBin(1023);

    return 0;

}

void convertiBin(int bin) {
    if (bin != 0) {
        convertiBin(bin / 2);
        printf("%d", bin % 2);
    }
}