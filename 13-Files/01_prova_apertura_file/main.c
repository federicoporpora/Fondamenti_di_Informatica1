#define _CRT_SECURE_NO_DEPRECATE

/*
    Realizzare un programma che, aperto un file di testo di nome “Prova.txt” in modalità “scrittura”, provveda a leggere
    da input delle parole separate da spazi (stringhe di al più 63 caratteri) e le scriva nel file di testo.
    Il programma termina quando l’utente inserisce la parola “fine”. Si abbbia cura di chiudere il file prima di
    terminare definitivamente il programma.
    Si controlli il corretto funzionamento del programma accedendo direttamente al file di testo con un editor
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    char str[64];
    FILE* file;

    if ((file = fopen("testo.txt", "w")) == NULL) {
        printf("Il file non e' stato aperto");
        return 1;
    }

    do {
        printf("Inserire una stringa da inserire nel file di testo: ");
        scanf("%s", str);
        if (strcmp(str, "fine") != 0) {
            fprintf(file, "%s ", str);
        }
    } while (strcmp(str, "fine") != 0);

    fclose(file);

    return 0;

}