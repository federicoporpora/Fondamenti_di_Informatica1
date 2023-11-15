#define _CRT_SECURE_NO_DEPRECATE

/*
	Creare un programma che legga da input una sequenza di interi positivi. In particolare, l’utente inserisce un numero iniziale con cui specifica quanti numeri
	è intenzionato ad inserire (al max 10). Di seguito poi inserisce i numeri, tutti in ordine strettamente crescente.
	In fase di lettura, il programma controlli che ogni numero sia effettivamente maggiore del precedente (si scartino i valori che non rispettano tale criterio).
	In un secondo vettore si calcoli la differenza percentuale tra un valore ed il successivo (data dalla differenza tra i due valori, divisa poi per il
	primo valore e moltiplicato il tutto per 100)
	Si richieda poi all’utente un valore di soglia (in percentuale), e si stampino a video tutte le coppie di valori il cui aumento dal primo al
	secondo valore risulta essere, in percentuale, maggiore della soglia specificata
*/

#include <stdio.h>

void stampaVettori(int vettore[], int len);

int main() {

	int max, len = 0, n, values[9], i;
	double diffPerc[9], soglia;

	printf("Quanti numeri si vogliono inserire? ");
	scanf("%d", &max);

	do {
		printf("Inserire il %do valore: ", len + 1);
		scanf("%d", &n);
		if (len == 0 && n > 0) {
			values[len] = n;
			len++;
		}
		else if (len < max && n > values[len - 1] && n > 0) {
			values[len] = n;
			len++;
		}
		else if (n <= 0) {
			printf("Il numero e' negativo, riprova\n");
		}
		else {
			printf("Il numero non e' maggiore di quello precedente, riprova\n");
		}
	} while (len < max);

	for (i = 0; i < len - 1; i++) {
		diffPerc[i] = ((values[i + 1] - values[i]) / values[i]) * 100;
	}

	printf("Inserire il valore soglia percentuale (inserirlo senza il simbolo percentuale): ");
	scanf("%lf", &soglia);

	for (i = 0; i < len - 1; i++) {
		if (diffPerc[i] > soglia) {
			printf("%d - %d\n", values[i], values[i + 1]);
		}
	}

	return 0;

}

void stampaVettori(int vettore[], int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		if (i < len - 1) {
			printf("%d, ", vettore[i]);
		}
		else {
			printf("%d", vettore[i]);
		}
	}
	printf("]");
}