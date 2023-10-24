#include <stdio.h>

// Realizzare un programma che legga da input tre numeri interi e stampi a video la loro somma e la media.

int main()
{

	int x, y, z;

	printf("Inserire tre numeri (con spazio): ");
	scanf_s("%d %d %d", &x, &y, &z);

	double sum = x + y + z;

	double avg = sum / 3;

	printf("La somma dei tre numeri e' %lf, mentre la media e' %lf", sum, avg);

	return 0;

}