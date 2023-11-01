#include <math.h>
#include "myMath.h"

int mioMin(int a, int b) {
	int min;
	min = (a < b) ? a : b;
	return min;
}

int mioMax(int a, int b) {
	int max;
	max = (a > b) ? a : b;
	return max;
}

int MCD(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a > b) {
		MCD(a - b, b);
	}
	else {
		MCD(a, b - a);
	}
}

int mcm(int a, int b) {
	return (a * b) / MCD(a, b);
}

int fattoriale(int a) {
	if (a < 0) {
		return 0;
	}
	else if (a == 0 || a == 1) {
		return 1;
	}
	else {
		return a * fattoriale(a - 1);
	}
}

int coeff_bin(int n, int k) {
	return fattoriale(n) / (fattoriale(k) * fattoriale(n - k));
}

double myLog(double a, double b) {
	return log(b) / log(a);
}

int sum_under(int a) {
	if (a <= 0) {
		return 0;
	}
	else {
		return a + sum_under(a - 1);
	}
}

void swap_and_commerciale(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}