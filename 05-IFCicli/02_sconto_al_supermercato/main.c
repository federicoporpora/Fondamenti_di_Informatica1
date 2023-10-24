#include <stdio.h>

/*
	Realizzare un programma che legga da input tre float rappresentanti tre prezzi di tre oggetti acquistati…
	stampi il totale della spesa, applicando lo sconto determinato dal bollone sul prezzo più alto
*/

int main()
{

	float x, y, z;
	printf("Inserire il prezzo dei tre prodotti acquistati (con spazio): ");
	scanf_s("%f %f %f", &x, &y, &z);

	float max, delta;
	max = (x >= y) ? x : y;
	max = (max >= z) ? max : z;

	delta = max * 0.1;

	float sum;
	sum = (x + y + z) - delta;

	printf("Il costo totale della spesa e' %f", sum);

	return 0;

}