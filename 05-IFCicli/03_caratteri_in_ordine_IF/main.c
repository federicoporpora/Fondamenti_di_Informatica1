#include <stdio.h>

/*
	Stampa di caratteri in ordine alfabetico Realizzare un programma che legga da input tre caratteri, e li stampi in ordine alfabetico
	Per determinare il secondo carattere, utilizzare if innestati
*/

int main()
{

	char c1, c2, c3;
	char first, second, third;

	printf("Inserire tre caratteri da mettere in ordine (con spazio): ");
	scanf_s("%c %c %c", &c1, 1, &c2, 1, &c3, 1);

	first = (c1 > c2) ? c1 : c2;			// first carattere piu' grande
	first = (first > c3) ? first : c3;

	third = (c1 < c2) ? c1 : c2;			// third carattere piu' piccolo
	third = (third < c3) ? third : c3;

	if (((c1 > c2) && (c2 > c3)) || ((c3 > c2) && (c2 > c1))) { //c2 carattere centrale
		second = c2;
	}
	else {
		if (((c2 > c1) && (c1 > c3)) || ((c3 > c1) && (c1 > c2))) { //c1 carattere centrale
			second = c1;
		}
		else { //c3 carattere centrale
			second = c3;
		}
	}

	printf("L'ordine dei caratteri e' %c %c %c", first, second, third);

	return 0;

}