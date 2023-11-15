#include <math.h>
#include "myMath.h"
#include <stdio.h>

int myMin(int a, int b) {
	return (a < b) ? a : b;
}

int myMax(int a, int b) {
	return (a > b) ? a : b;
}

int myMCD(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a > b) {
		myMCD(a - b, b);
	}
	else {
		myMCD(a, b - a);
	}
}

int myMcm(int a, int b) {
	return (a * b) / myMCD(a, b);
}

int myFattoriale(int a) {
	if (a < 0) {
		return 0;
	}
	else if (a == 0 || a == 1) {
		return 1;
	}
	else {
		return a * myFattoriale(a - 1);
	}
}

int myPow(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int myCoeffBin(int n, int k) {
	return myFattoriale(n) / (myFattoriale(k) * myFattoriale(n - k));
}

double myLog(double a, double b) {
	return log(b) / log(a);
}

int mySumUnder(int a) {
	if (a <= 0) {
		return 0;
	}
	else {
		return a + mySumUnder(a - 1);
	}
}

void mySwap(int *a, int *b) {
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

void stampaVettori(int vettore[], int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		if (i < len - 1) {
			printf("%d, ", vettore[i]);
		}
		else {
			printf("%d", vettore[i]);
		}
	}
	printf("]");
}