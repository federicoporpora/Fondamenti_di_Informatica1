#define _CRT_SECURE_NO_DEPRECATE

/*
    Un sistema di cronometraggio per la Formula 1 registra i tempi in millisecondi. Tuttavia tali tempi devono essere presentati in termini di minuti, secondi e millisec.
    Creare una procedura che, ricevuti in ingresso un tempo dato in millisecondi, restituisca l’equivalente in termini di minuti, secondi, millisec.
    (tramite eventuali parametri passati per riferimento)
    Si realizzi un main che invochi la funzione e che, dopo aver chiesto all’utente un valore indicante una durata in millisecondi, stampi a video il tempo nel formato
    min:sec.millisec
*/

#include <stdio.h>
#include "myLib.h"

int main() {

    int ms_i, min, sec, ms_f;
    min = sec = 00;
    ms_f = 000;
    printf("Valore iniziale di millisecondi: ");
    scanf("%d", &ms_i);
    ms_to_norm(ms_i, &min, &sec, &ms_f);
    printf("Tempo: %d:%02d.%03d", min, sec, ms_f);

    return 0;

}