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

int myPow(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
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

int myLen(int a) {
	int new_num = a;
	int i = 0;
	while (new_num != 0) {
		new_num /= 10;
		i++;
	}
	return i;
}

int myPalindromo(int x) {
	if (x == 0) {
		return 1;
	}
	if (x < 0) {
		return 0;
	}
	int int_sx, int_dx;
	for (int i = 1; i <= myLen(x); i++) {
		int_sx = (x / myPow(10, myLen(x) - i)) % 10;
		int_dx = (x / myPow(10, i - 1)) % 10;
		if (int_sx != int_dx) {
			return 0;
			break;
		}
	}
	return 1;
}

int mySqrt(int x) {
	int i;
	int result = 0;
	for (i = 1; myPow(i, 2) <= x; i++) {
		result = i;
	}
	return result;
}