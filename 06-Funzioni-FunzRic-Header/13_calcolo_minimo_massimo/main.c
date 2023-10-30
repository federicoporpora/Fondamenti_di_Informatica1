#define _CRT_SECURE_NO_DEPRECATE

/*
	Realizzare un programma che calcoli il minimo e il massimo di una serie di valori
	Il numero di valori deve essere costante e definito tramite una opportuna costante simbolica
	Se la differenza tra il massimo e il minimo supera 10, il programma termina, altrimenti aspetta una nuova serie di valori
	Incapsulare il calcolo del minimo e del massimo in funzioni apposite, definite in un apposito modulo
*/

#include <stdio.h>
#include "myMath.h"
#define N 10

int main() {

	int i, max, min, n;
	printf("Inserire il 1 valore: ");
	scanf("%d", &n);
	max = min = n;

	
	for (i = 2; i <= N; i++) {
		printf("Inserire il %d valore: ", i);
		scanf_s("%d", &n);
		max = mioMax(n, max);
		min = mioMin(n, min);
		if (max - min >= 10) {
			break;
		}
	}
	

	printf("Il massimo e' %d, mentre il minimo e' %d", max, min);

	return 0;

}