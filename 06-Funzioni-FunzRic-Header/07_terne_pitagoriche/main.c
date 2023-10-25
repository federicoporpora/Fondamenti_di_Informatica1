#define _CRT_SECURE_NO_DEPRECATE

/*
	Codificare in C un programma che chieda di inserire un limite (un intero positivo), e stampi a video tutte le terne pitagoriche
	i cui valori sono compresi tra 1 e il limite indicato.
*/

#include <stdio.h>

int isTerna(int c1, int c2, int i);

int main() {

	int n, c1, c2, i, x;
	x = 1;

	printf("Inserire il limite \"n\": ");
	scanf_s("%d", &n);

	for (i = 5; i <= n; i++) {
		for (c2 = 4; c2 < i; c2++) {
			for (c1 = 3; c1 < c2; c1++) {
				if (isTerna(c1, c2, i) == 1) {
					printf("%da terna: %d, %d, %d\n", x, c1, c2, i);
					x++;
				}
			}
		}
	}

	return 0;

}

int isTerna(int c1, int c2, int i) { // se e' una terna stampa 1, senno' 0 (i valori devono essere ordinati)
	if ((c1 * c1) + (c2 * c2) == (i * i)) {
		return 1;
	}
	else {
		return 0;
	}
}