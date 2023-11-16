#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input due sequenze di interi, di lunghezza non nota a priori (al più 10), e terminate da 0.
    A tal fine, si realizzi una funzione apposita che riceva come parametri un vettore vuoto (da riempire) e la sua dimensione fisica
    e restituisca la dimensione logica.
    Per semplicità, si ipotizzi che ogni sequenza non contenga elementi ripetuti
    Il programma poi memorizzi in un terzo vettore tutti gli elementi che compaiono in entrambi gli array iniziali (intersezione)
	e lo si stampi a video
*/

#include <stdio.h>
#define DIM 10

void stampaVettori(int vettore[], int len);
int riempiVettori(int values[], int dim);


int main() {

	int len1, len2, len3 = 0, values1[DIM], values2[DIM], values3[DIM], i, j;

	len1 = riempiVettori(values1, DIM);
	len2 = riempiVettori(values2, DIM);

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (values1[i] == values2[j]) {
				values3[len3] = values1[i];
				len3++;
			}
		}
	}

	stampaVettori(values3, len3);

    return 0;

}

int riempiVettori(int values[], int dim) {
	int n, len = 0;
	do {
		printf("Inserire un numero: ");
		scanf("%d", &n);
		if (n != 0 && len < dim) {
			values[len] = n;
			len++;
		}

	} while (len < dim && n != 0);
	return len;
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