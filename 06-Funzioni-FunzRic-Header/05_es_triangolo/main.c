#define _CRT_SECURE_NO_DEPRECATE

/*
	Codificare in C la funzione "float perimetro(float a, float b, float c)" che, dati i lati a,b,c di un triangolo, ne calcoli il perimetro.
	Codificare in C la funzione "float area(float a, float b, float c)" che restituisca l’area di un triangolo i cui lati misurano a, b, c.
	A tal scopo si usi la formula di Erone.
	A tal scopo si includa l’header <math.h> e si utilizzi la funzione sqrt(x).
	Definire un possibile main che prenda in ingresso i tre lati di un triangolo e stampi perimetro ed area.
*/

#include <stdio.h>
#include <math.h>

float perimetro(float a, float b, float c);
float area(float a, float b, float c);

int main() {

	float a, b, c;

	printf("Inserire i tre lati di un triangolo di cui calcolero' il perimetro e l'area: ");
	scanf_s("%f%f%f", &a, &b, &c);

	printf("Il perimetro del triangolo vale: %f\nL'area del triangolo vale: %f", perimetro(a, b, c), area(a, b, c));

	return 0;

}

float perimetro(float a, float b, float c) {
	return (a + b + c);
}

float area(float a, float b, float c) {
	float p;
	p = (perimetro(a, b, c)) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}