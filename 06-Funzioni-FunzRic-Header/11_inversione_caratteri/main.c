#define _CRT_SECURE_NO_DEPRECATE

/*
    Si scriva una programma che legga da input una sequenza di caratteri terminati dal tasto “invio”, e stampi a video tale sequenza in ordine invertito.
    Il programma stampi a video anche il numero di caratteri inseriti.
    A tal fine, si realizzi tale funzionalità tramite una funzione ricorsiva
*/

#include <stdio.h>

int invert();

int main() {
    
    printf("Inserire una serie di caratteri, stampero' i caratteri invertiti di posizione ed il numero di caratteri. ");
    printf(" %d", invert());

    return 0;

}

int invert() {
    char carattere = getchar();
    int i = 0;
    if (carattere != '\n' && carattere != EOF) {
        i += invert();
        putchar(carattere);
    }
    return i;
}