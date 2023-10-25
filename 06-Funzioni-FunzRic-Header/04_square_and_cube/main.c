#define _CRT_SECURE_NO_DEPRECATE

/*
	Creare una funzione float square(float x). La funzione deve restituire il quadrato del parametro x.
	Creare un’altra funzione, di nome float cube(float x), che restituisca invece il cubo del valore x.
	Progettare quindi e codificare un programma che legga un float da tastiera e restituisca il suo quadrato ed il suo cubo.
*/

#include <stdio.h>

float square(float x);
float cube(float x);

int main() {

	float x, squared, cubed;

	printf("Inserire il valore di cui calcolero' il quadrato ed il cubo: ");
	scanf("%f", &x);

	squared = square(x);
	cubed = cube(x);

	printf("Quadrato di %f: %f\nCubo di %f: %f", x, squared, x, cubed);

	return 0;

}

float square(float x) {
	float square;
	square = x * x;
	return square;
}

float cube(float x) {
	float cube;
	cube = x * x * x;
	return cube;
}