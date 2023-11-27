#define _CRT_SECURE_NO_DEPRECATE

/*
    Conversione di numeri interi in rappresentazione a modulo 2 e operazioni
    Si realizzi un programma capace di
    Effettuare la conversione da numeri interi (con segno!) alla corrispondente rappresentazione in modulo 2
    e viceversa
    Effettuare la somma e sottrazione di due numeri interi utilizzando la rappresentazione in modulo 2
    Si utilizzino le stringhe per la rappresentazione in modulo 2

    In particolare, si definiscano le seguenti funzioni
        int convertiBin(char* bin);
    – Ottenere la codifica binaria del valore assoluto e convertire quella
        RESULT convertiInt(int value, char* res);
    – Dove RESULT può valere
        • OK se la conversione è stata effettuata con successo
        • SIZE_OVERFLOW se la dimensione fisica di res non è abbastanza grande per contenere la conversione
    – si utilizzi il logaritmo in base 2 per calcolare lo spazio necessario, e si considerino segno e
    terminatore
    
    Facciamo in modo che le stringhe siano riempite sempre per tutta la dimensione fisica
    
        void invertiSegno(char *num, char *res);
    - Inverte il segno di num (ovvero realizza l’algoritmo del modulo 2)
        • PASSO 1: inversione dei bit
        • PASSO 2: aggiunta di uno
    – Suggerimento: si converta l’intero 1 in binario e si utilizzi la funzione sum (vedi sotto)

        RESULT sum(char *add1, char *add2, char *res);
    – Somma i due numeri binari (controllare che abbiano la stessa lunghezza)
    – Restituisce SIZE_OVERFLOW se l’operazione causa overflow (x-or dei due carry più significativi)
    • NOTA: si faccia in modo che le funzioni calcolino un risultato corretto anche passando come risultato
    una delle variabili date in input
    – Es: invertiSegno(num, num) deve invertire correttamente il segno di num (dopo l’invocazione, num
    contiene il risultato)
*/

#include <stdio.h>

int main() {



    return 0;

}