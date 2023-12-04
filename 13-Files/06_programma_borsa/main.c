#define _CRT_SECURE_NO_DEPRECATE

/*
    Un sito web per le speculazioni borsistiche registra su un file di testo gli andamenti di alcuni titoli
    azionari. In particolare, su ogni riga del file, registra il nome di un titolo (al più 63 caratteri senza
    spazi), i valori di apertura e di chiusura del titolo (tramite due float), ed il giorno dell’anno corrente
    in cui è stato monitorato il titolo (un intero).

    Nel file non c’è nessun ordine preciso con cui le righe sono state memorizzate, e mano a mano che passano i
    giorni vengono registrate più e più righe relative allo stesso titolo. Il sito web ha comunque l’accortezza
    di registrare nel file al massimo 100 righe relative allo stesso titolo.
    
    Si vuole realizzare un programma per valutare la volatilità di un titolo (cioè i valori minimi e massimi
    raggiunti), relativamente alle informazioni presenti sul file.
    
    A tal scopo, in un opportuno modulo software azioni.h/azioni.c:
    
    Si definisca una apposita struttura dati, di nome “Azione”, per memorizzare le informazioni relative ad un
    titolo.
    
    Si realizzi una funzione:
        int leggi(FILE* fp, azione dest[], int dim, char * nome);
    che, ricevuti in ingresso un puntatore ad un file già opportunamente aperto, un array di strutture azione e
    la sua dimensione fisica dim, ed il nome di un titolo azionario, provveda a copiare in dest tutte le
    strutture relative all’azione specificata. La funzione deve restituire il numero di elementi copiati, ovvero
    la dimensione logica del vettore dest.

    Quindi, in un altro modulo software “trova.h/trova.c”:

    Si realizzi una funzione:
        azione trovaMin(azione src[], int dim, float* val);
    che, ricevuti in ingresso un array di strutture azione e la sua dimensione dim, ed il nome di una azione,
    determini il valore minimo raggiunto dal titolo azionario (le cui fluttuazioni sono memorizzate in src).
    La funzione deve restituire la struttura dati azione relativa a quando si è verificato il minimo, e tramite
    il parametro val passato per riferimento deve restituire il minimo raggiunto.

    Si realizzi una funzione:
        azione trovaMax(azione src[], int dim, float* val);
    che, ricevuti in ingresso un array di strutture azione e la sua dimensione dim, ed il nome di una azione,
    determini il valore massimo raggiunto dal titolo azionario (Ie cui fluttuazioni sono memorizzate in src).
    La funzione deve restituire la struttura dati azione relativa a quando si è verificato il massimo, e tramite
    il parametro val passato per riferimento deve restituire il massimo raggiunto.

    Si realizzi un programma main.c che, utilizzando le funzioni già definite, provveda a chiedere all’utente il
    nome di un titolo azionario, e stampi a video i valori minimi e massimi raggiunti dalle quotazioni del
    titolo.
    
    Si estenda il modulo “trova.h/trova.c” con una funzione opportuna per calcolare la media del valore del
    titolo azionario rispetto alle varie quotazioni registrate, e poi si provveda a stampare a video
    l’oscillazione (in percentuale rispetto al valore medio) del minimo e del massimo raggiunti dal titolo in
    borsa.
*/

#include <stdio.h>
#include <stdlib.h>
#include "azioni.h"

#define DIM 100

int main() {

    char nome[64];

    printf("Inserire il nome di un titolo azionario: ");
    scanf("%s", nome);

    FILE* fp;

    if ((fp = fopen("op.txt", "r")) == NULL) {
        printf("Il file non e' stato aperto correttamente.");
        exit(1);
    }

    azione arr[DIM];

    leggi(fp, arr, DIM, &nome);

    azione minimo, massimo;
    float min, max;

    minimo = trovaMin(arr, DIM, &min);
    massimo = trovaMax(arr, DIM, &max);

    printf("Minimo: %f, massimo: %f", min, max);

    fclose(fp);

    return 0;

}