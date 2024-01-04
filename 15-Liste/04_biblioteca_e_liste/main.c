#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "funzioni.h"

int main() {
	FILE* fp;
	volume V[31];

	if ((fp = fopen("archivio.txt", "r")) == NULL) {
		perror("File doesn't exist");
		exit(1);
	}

	int len = creaVettoreDaFile(fp, V);
	stampaV(V, len); // punto 1

	printf("\n");

	list L = creaLista(V, len);
	showList(L); // punto 2

	float rapporto = stampaRapporti(V, L, len); // punto 3

	int rigaDaStampare = piuDisponibili(L);
	rewind(fp);
	stampaRiga(fp, rigaDaStampare); //punto 4

	fclose(fp);
	freelist(L);

	return 0;
}