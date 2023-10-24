#include <stdio.h>

/*

	1. Realizzare un programma che legga da input due numeri reali, e ne stampi a video il valore massimo
	2. Al fine di determinare il massimo, si utilizzino le sole espressioni condizionali

*/

int main()
{

	double x, y, max;
	printf("Inserire due numeri reali (con spazio): ");
	scanf_s("%lf %lf", &x, &y);

	max = (x > y) ? x : y;
	printf("Il valore massimo e' %lf", max);

	return 0;

}