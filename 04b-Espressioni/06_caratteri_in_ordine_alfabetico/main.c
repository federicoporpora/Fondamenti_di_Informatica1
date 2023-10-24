#include <stdio.h>

/*
	1. Realizzare un programma che legga da input tre caratteri e li stampi in ordine alfabetico.
		A tal scopo, si rammenti la rappresentazione dei caratteri in linguaggio C…
	2. Si utilizzino solo le espressioni condizionali (e non l’istruzione if… ad esempio)
*/

int main()
{

	char c1, c2, c3;
	char first, second, third;

	printf("Inserire tre caratteri (con spazio): ");
	scanf_s("%c %c %c", &c1, 1, &c2, 1, &c3, 1);

	first = (c1 < c2) ? c1 : c2;
	first = (first < c3) ? first : c3;

	third = (c1 > c2) ? c1 : c2;
	third = (third > c3) ? third : c3;

	second = c1 + c2 + c3 - first - third;

	printf("I numeri in ordine alfabetico sono: %c %c %c", first, second, third);

	return 0;

}