#include <stdio.h>

typedef struct {
	float importo;
	int nOggetti;
} scontrino;

int leggi(FILE* fp, scontrino* dest);
int scrivi(FILE* fp, scontrino src);