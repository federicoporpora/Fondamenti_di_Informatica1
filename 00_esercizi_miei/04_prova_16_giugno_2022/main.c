#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "myLib.h"
#include "libri.h"

int main() {

	Libro* elenco;
	int dim;

	elenco = leggiLibri("store.txt", &dim);

	stampaStore(elenco, dim);

	list richieste = leggiRichieste("richieste.txt");

	while (!empty(richieste)) {
		printElement(head(richieste));
		richieste = tail(richieste);
	}

	return 0;
}