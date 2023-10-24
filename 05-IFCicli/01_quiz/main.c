#include <stdio.h>

int main() {

	int a = 5, b = 5, c = 5;

	if (a > 0 || (a = a + 1))	// essendoci l'operatore ||, OR, dato che la prima operazione e' vera, al computer basta e per questo non la esegue, quindi a rimane 5 e viene stampato.
		printf("%d", a);		// stampa a == 5

	if (b > 0 && (b = b + 1))	// essendoci invece AND, entrambe le operazioni vengono controllate e svolte. diviene b > 0 (vero) e b = 6 (diverso da 0 quindi vero). quindi viene stampata b
		printf("%d", b);		// stampa b == 6

	if (c > 0 && (c = c - 5))	// con l'AND c > 0 e' vero, mentre c - 5 da' come valore 0, cioe' falso, quindi non viene stampato nulla
		printf("%d", c);		// non stampa nulla

}