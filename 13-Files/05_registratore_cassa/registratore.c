#include "registratore.h"

int leggi(FILE* fp, scontrino* dest) {
	return fread(dest, sizeof(scontrino), 1, fp);
}

int scrivi(FILE* fp, scontrino src) {
	return fwrite(&src, sizeof(scontrino), 1, fp);
}