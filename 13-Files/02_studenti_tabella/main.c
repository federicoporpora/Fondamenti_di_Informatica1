#define _CRT_SECURE_NO_DEPRECATE

/*
    Sia dato il file di testo "dati.txt" contenente i dati relativi agli studenti immatricolati al primo anno della
    Facoltà di Ingegneria

    In particolare, le informazioni sono memorizzate nel file "dati.txt" come segue: ognuna delle linee del file
    contiene i dati relativi ad un nuovo studente; in particolare:

    1 Matricola: un intero che indica il numero di matricola dello studente
    2 CdL: un intero che indica il corso di laurea (CdL) dello studente (es. 2145)

    Sia dato un secondo file di testo, “indirizzi.txt” che contiene, invece, l’indirizzo di ogni studente, e in
    particolare, in ogni linea, separati da uno spazio:

    • Matricola: il numero di matricola dello studente (un intero)
    • Nome: il nome dello studente, al più 20 caratteri senza spazi
    • Cognome: il cognome dello studente, al più 30 caratteri senza spazi
    • Via: una stringa di al più 30 caratteri senza spazi, che riporta la via di residenza dello studente
    • Città: una stringa che riporta la città di residenza dello studente, al più 30 caratteri senza spazi
    • CAP: un intero che rappresenta il codice di avviamento postale dello studente

    Si scriva un programma in linguaggio C che:
    
    1. A partire dai file "dati.txt" e “indirizzi.txt” costruisca una tabella T contenente, per ogni studente, Matricola,
    Nome, Cognome, Via, Città, CAP e CdL.
    Si ricorda l’esistenza della procedura di libreria void rewind (FILE *f) che riporta la testina di lettura a inizio
    file

    2. A partire dalla tabella T, e dato da input un intero C che rappresenta un CdL, stampi la percentuale di studenti
    (rispetto al numero totale delle matricole) iscritti al corso C [Ad esempio, se il numero totale delle matricole è
    1000, e quello degli studenti iscritti a C è 200, il programma stamperà “20%”]
    
    3. Scriva su un terzo file di testo “bologna.txt”, nome, cognome e numero di matricola di tutti gli studenti che
    abitano a Bologna
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 100

typedef struct {
    int matricola, CdL, CAP;
    char nome[21], cognome[31], via[31], citta[31];
} persona;

int main() {

    FILE *fDati, *fInd;
    persona persone[DIM];
    int nPersone, i;

    if ((fDati = fopen("dati.txt", "r")) == NULL) { //controllo apertura file dati.txt
        printf("Il file dati.txt non si e' aperto");
        exit(1);
    }

    if ((fInd = fopen("indirizzi.txt", "r")) == NULL) { //controllo apertura file indirizzi.txt
        printf("Il file indirizzi.txt non si e' aperto");
        exit(1);
    }



    // PARTE 1

    nPersone = 0;
    int matricola, CdL;

    while ((fscanf(fDati, "%d%d\n", &matricola, &CdL)) != EOF) { //assegnazione nell'array dei dati matricola e CdL
        persone[nPersone].matricola = matricola;                  //dal file dati.txt
        persone[nPersone].CdL = CdL;
        nPersone++;
    }

    char nome[21], cognome[31], via[31], citta[31];
    int CAP, j;

    while ((fscanf(fInd, "%d %s %s %s %s %d\n", &matricola, nome, cognome, via, citta, &CAP)) != EOF) {
        for (i = 0; i < nPersone; i++) {            //assegnazione dei vari dati dal file indirizzo.txt
            if (matricola == persone[i].matricola) {
                strcpy(persone[i].nome, nome);
                strcpy(persone[i].cognome, cognome);
                strcpy(persone[i].via, via);
                strcpy(persone[i].citta, citta);
                persone[i].CAP = CAP;
            }
        }
    }

    for (i = 0; i < nPersone; i++) { //stampa della tabella
        printf("Matricola: %d\tNome: %-20s\tCognome: %-30s\tVia: %-30s\tCitta': %-30s\tCAP: %d\tCdL: %d\n", persone[i].matricola, persone[i].nome, persone[i].cognome, persone[i].via, persone[i].citta, persone[i].CAP, persone[i].CdL);
    }



    // PARTE 2

    int C, persone_in_CdL = 0;
    double percentuale;

    printf("\nInserire il codice del corso di cui si vuole sapere la percentuale: "); //ottenimento del codice
    scanf("%d", &C);

    for (i = 0; i < nPersone; i++) {
        if (persone[i].CdL == C) {
            persone_in_CdL++;
        }
    }

    percentuale = (persone_in_CdL * 100.0) / nPersone; //creazione della percentuale

    printf("\nLa percentuale di persone che presenta quel corso e' del %.2lf%%", percentuale); //stampa della percentuale



    // PARTE 3

    FILE* fBol;

    if ((fBol = fopen("bologna.txt", "w")) == NULL) { //controllo apertura file bologna.txt
        printf("Il file bologna.txt non si e' aperto");
        exit(1);
    }

    for (i = 0; i < nPersone; i++) {
        if (strcmp(persone[i].citta, "Bologna") == 0) {
            fprintf(fBol, "%s %s %d\n", persone[i].nome, persone[i].cognome, persone[i].matricola);
        }
    }

    fclose(fDati);
    fclose(fInd);
    fclose(fBol);

    return 0;

}