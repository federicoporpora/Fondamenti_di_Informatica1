#define _CRT_SECURE_NO_DEPRECATE

/*
	Codificare in C la funzione "int isPrimo(int x)" che restituisca:
	1 se x è un numero primo
	0 altrimenti.
	Si utilizzi a tal proposito l’operatore modulo (%).
	Si progetti un programma che legga da tastiera un numero N, e stampi a video tutti i numeri primi compresi tra 0 e N.
*/

#include <stdio.h>

int isPrimo(int x);

int main() {

	int n, i;
	printf("Inserire un numero \"n\" di cui stampero' tutti i numeri primi minori di esso: ");
	scanf_s("%d", &n);
	printf("I numeri primi minori di \"n\" sono: ");
	for (i = 2; i < n; i++) {
		if (isPrimo(i) == 1) {
			printf("%d, ", i);
		}
	}

	return 0;

}

int isPrimo(int x) {
	int i, primo;
	primo = 1;
	for (i = 2; i < x; i++) {
		if (x % i == 0) {
			primo = 0;
		}
	}
	return primo;
}