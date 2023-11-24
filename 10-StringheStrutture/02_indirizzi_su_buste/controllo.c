#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>

int indirizzo(char cognome[], char nome[], char indirizzo[], int dim) {


    int lenNome, lenCognome;
    char primaLettera[2];

    primaLettera[0] = nome[0];
    primaLettera[1] = '\0'; // Terminatore di stringa per primaLettera

    lenNome = strlen(nome);
    lenCognome = strlen(cognome);

    if (lenNome + lenCognome + 1 < dim) { // +1 per lo spazio tra cognome e nome
        strcpy(indirizzo, cognome);
        strcat(indirizzo, " "); // Aggiunge uno spazio
        strcat(indirizzo, nome);
        return 1;
    }
    else if (lenCognome + 2 < dim) { // +2 per spazio e punto dopo il cognome
        strcpy(indirizzo, cognome);
        strcat(indirizzo, " "); // Aggiunge uno spazio
        strncat(indirizzo, primaLettera, 1); // Aggiunge solo la prima lettera del nome
        strcat(indirizzo, ".");
        return 1;
    }
    else {
        return -1;
    }
    return 1;
}