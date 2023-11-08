#define _CRT_SECURE_NO_DEPRECATE

/*
    Un sistema di gestione mp3 permette di calcolare in anticipo la durata di una compilation di brani.
    Creare una procedura che, ricevuti in ingresso la durata di due pezzi musicali, in termini di ore, minuti e secondi,
    restituisca la durata risultante dalla somma dei due brani in termini di ore, minuti e secondi.
    Si realizzi un main che chieda all’utente di inserire la durata di diversi brani musicali, e si stampi a video la durata totale
    (l’utente segnala il termine dei brani da inserire con un brano speciale di lunghezza 0:00.00).
*/

#include <stdio.h>
#include "myLib.h"

int main() {

    int i = 1;
    int h, min, sec, h_fin, min_fin, sec_fin;
    h_fin = min_fin = sec_fin = 0;

    do {
        printf("Inserire la durata del %do brano: ", i);
        i++;
        scanf("%d:%d.%d", &h, &min, &sec);
        somma_tra_brani(h, min, sec, &h_fin, &min_fin, &sec_fin);
    } while (h != 0 || min != 0 || sec != 0);

    printf("Durata della compilation: %d:%02d.%02d\n", h_fin, min_fin, sec_fin);

    return 0;

}