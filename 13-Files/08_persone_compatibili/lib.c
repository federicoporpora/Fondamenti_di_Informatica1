#include "lib.h"
#include <stdlib.h>
#include <string.h>

int lettura(char nomeFile[], Persona elenco[], int dim) {
	FILE* fp;
	char temp, tolk;
	int i, j = 0, giorno, mese, anno, ifEOF;
	if ((fp = fopen(nomeFile, "r")) == NULL) {
		printf("Il file non e' stato aperto correttamente.");
		return -1;
	}
	for (i = 0; i < dim; i++) {
		if ((ifEOF = fscanf(fp, "%c", &temp)) != ';' && j < 21 && ifEOF != EOF) {
			while (fscanf(fp, "%c", &temp) != ';' && j < 21) {
				elenco[i].nome[j] = temp;
				j++;
			}
			j = 0;
			while (fscanf(fp, "%c", &temp) != ';' && j < 21) {
				elenco[i].cognome[j] = temp;
				j++;
			}
		}
	}
}