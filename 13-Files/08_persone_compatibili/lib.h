#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[21], cognome[21], tolk;
	int giorno, mese, anno;
} Persona;

int lettura(char nomeFile[], Persona elenco[], int dim);