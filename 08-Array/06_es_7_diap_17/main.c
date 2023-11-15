#define _CRT_SECURE_NO_DEPRECATE

/*
	Scrivere un programma che
	1) Legga da input due vettori V1 e V2 di interi di dimensione N;
	2) costruisca un terzo vettore V3 di dimensione 2N i cui elementi di posizione pari siano gli elementi del primo vettore e gli elementi di posizione dispari siano
	gli elementi del secondo vettore.
*/

#include <stdio.h>
#define DIM 10

int main() {

	int num, counter1, counter2, i;
	int values_1[DIM], values_2[DIM], values_3[DIM * 2];
	counter1 = counter2 = 0;

	do {
		printf("Inserisci un numero per il primo vettore: ");
		scanf_s("%d", &num);
		if (num != 0 && counter1 < DIM) {
			values_1[counter1] = num;
			counter1++;
		}
	} while (num != 0 && counter1 < DIM);

	do {
		printf("Inserisci un numero per il secondo vettore: ");
		scanf_s("%d", &num);
		if (num != 0 && counter2 < DIM) {
			values_2[counter2] = num;
			counter2++;
		}
	} while (num != 0 && counter2 < DIM);

	for (i = 0; i < (DIM * 2) - 1; i++) {
		if (i % 2 == 0) {
			values_3[i] = values_1[i / 2];
		}
		else {
			values_3[i] = values_2[i / 2];
		}
	}

	printf("[");
	for (int j = 0; j < (counter1 + counter2); j++) {
		if (j < ((counter1 + counter2) - 1))
		{
			printf("%d, ", values_3[j]);
		}
		else {
			printf("%d", values_3[j]);
		}
	}
	printf("]");

	return 0;

}