#define _CRT_SECURE_NO_DEPRECATE

/*
	Si scriva una funzione "int sommaPotenze(int a,int n);" che dati a e n deve calcolare (sommatoria da i=1 ad n di a^i)
	A tal fine si scriva una funzione "int potenza(int x,int y);" che dati x e y deve calcolare x^y usando come operazione primitiva il prodotto.
*/

#include <stdio.h>

int potenza(int x, int y);
int sommaPotenze(int a, int n);

int main() {

	int a, n, sum;

	printf("Inserire la base \"a\" della potenza: ");
	scanf("%d", &a);
	printf("Inserire il limite \"n\" della sommatoria: ");
	scanf("%d", &n);

	sum = sommaPotenze(a, n);

	printf("Il risultato della sommatoria e' %d", sum);

	return 0;

}

int potenza(int x, int y) {
	int pow, i;
	pow = 1;
	for (i = 0; i < y; i++) {
		pow *= x;
	}
	return pow;
}

int sommaPotenze(int a, int n) {
	int i, sum;
	sum = 0;
	for (i = 1; i <= n; i++) {
		sum += potenza(a, i);
	}
	return sum;
}