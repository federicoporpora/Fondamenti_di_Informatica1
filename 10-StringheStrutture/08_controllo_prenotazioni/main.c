#define _CRT_SECURE_NO_DEPRECATE

/*
    Una compagnia di autobus che effettua servizio su lunghe distanze vuole realizzare un programma di
    controllo delle prenotazioni dei posti.
    A tal scopo rappresenta ogni prenotazione tramite una struttura booking contenente nome del cliente
    (al massimo 1023 caratteri, senza spazi) e numero del posto prenotato (un intero).
    Le prenotazioni effettuate vengono registrate tramite un array (di dimensione prefissata DIM)
    di strutture booking, di dimensione logica iniziale pari a 0.
    Si realizzi il modulo C gestione.h/gestione.c, contenente la struttura dati booking e le seguenti funzioni…

    a) Si realizzi una funzione:
        int leggi(booking * dest);
    La funzione legge da input una struttura di tipo booking (nome cliente, numero posto)
    rappresentante una richiesta di prenotazione, e provvede a memorizzarla in dest.
    Se l’utente inserisce come nome del cliente la stringa "fine" o la stringa "stampa",
    allora la funzione deve restituire i valori 0 e -1, rispettivamente.
    Altrimenti la funzione deve restituire 1, a significare l’inserimento corretto di una nuova richiesta
    di prenotazione.

    b) Si realizzi una funzione:
    int assegna(booking list[], int dim, int* lengthList, char* name, int pref);
    La funzione riceve in ingresso l’array di prenotazioni e la sua dimensione fisica e logica,
    e poi il nome del cliente ed il posto da lui indicato. La funzione deve controllare che il posto
    indicato non sia già stato assegnato, ed in caso contrario deve restituire il valore 0.

    Qualora invece il posto sia ancora libero, la funzione deve assegnare tale posto al cliente copiando i dati
    della prenotazione nell’ultima posizione libera nell’array, e deve provvedere ad aggiornare correttamente
    la dimensione logica dell’array. In questo secondo caso la funzione deve invece restituire come valore 1,
    indicante il successo nella prenotazione.
    Al fine di copiare il nome del cliente, si utilizzi la funzione di libreria
        char * strcpy(char * s, char * ct)
    che copia ct in s (terminatore compreso).

    c) Si realizzi un programma main (file main.c) che chieda all’operatore di inserire una richiesta di
    prenotazione (a tal fine si usi la funzione di cui al punto a).
    Il programma deve cercare di registrare la prenotazione tramite la funzione assegna;
    qualora l’operazione di prenotazione fallisca (perché il posto risulta essere già assegnato),
    il programma provveda a chiedere all’operatore di inserire una nuova richiesta prenotazione, finché
    non si riesca ad effettuare con successo una prenotazione.

    Qualora l’operatore inserisca il nome “fine”, il programma deve terminare; qualora invece venga
    inserita la stringa “stampa”, il programma deve stampare a video le prenotazioni già effettuate. Si noti
    che la funzione di cui al punto (a) restituisce un codice specifico per indicare quale stringa sia
    stata inserita.
*/

#include <stdio.h>
#include <string.h>
#define DIM 10
#define FINE -1
#define STAMPA 0
#define NOME 1
#define OCCUPATO 0
#define LIBERO 1

typedef struct Booking {
    char name[1024];
    int seat;
} booking;

int leggi(booking* dest);
int assegna(booking list[], int dim, int* lengthList, char name, int pref);

int main() {

    booking prenotazione, listaPrenotazioni[DIM];
    int richiesta, nPrenotazioni = 0, i;
    
    while ((richiesta = leggi(&prenotazione)) == NOME) {
        if (richiesta == NOME) {
            if (assegna(listaPrenotazioni, DIM, &nPrenotazioni, &prenotazione.name, prenotazione.seat) == OCCUPATO) {
                printf("Il posto richiesto e' occupato, riprovare");
            }
        }
    }
    if (richiesta == STAMPA) {
        for (i = 0; i < nPrenotazioni; i++) {
            printf("\nPrenotazione %d: %s, posto %d", i + 1, listaPrenotazioni[i].name, listaPrenotazioni[i].seat);
        }
    }
    if (richiesta == FINE) {
        return 0;
    }
    return 0;

}

int leggi(booking* dest) {
    char tempName[1024];
    printf("Inserire il nome del cliente (max 1023 caratteri senza spazi): ");
    scanf("%s", &tempName);
    if (strcmp(tempName, "fine") == 0) {
        return FINE;
    }
    if (strcmp(tempName, "stampa") == 0) {
        return STAMPA;
    }
    else {
        strcpy((*dest).name, tempName);
        printf("Inserire il numero del posto: ");
        scanf("%d", &(*dest).seat);
    }
    return NOME;
}

int assegna(booking list[], int dim, int* lengthList, char name, int pref) {
    int i;
    for (i = 0; i < (*lengthList); i++) {
        if (list[i].seat == pref) {
            return OCCUPATO;
        }
    }
    strncpy(list[*lengthList].name, name, sizeof(list[*lengthList].name) - 1);
    list[*lengthList].name[sizeof(list[*lengthList].name) - 1] = '\0';

}