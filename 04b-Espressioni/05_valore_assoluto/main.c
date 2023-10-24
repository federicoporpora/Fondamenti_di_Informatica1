#include <stdio.h>

/*
	Realizzare un programma che legga da input un numero reale, e stampi a video:
		1. il suo valore assoluto
		2. La parte intera del suo valore assoluto
*/

int main()
{

	double x, abs_x;
	int abs_x_int;

	printf("Inserire un numero reale: ");
	scanf_s("%lf", &x);
	abs_x = (x < 0) ? -x : x;
	abs_x_int = (int)abs_x;

	printf("Il valore assoluto e' %lf, la parte intera %d", abs_x, abs_x_int);

	return 0;

}