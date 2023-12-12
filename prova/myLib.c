#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myLib.h"

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

void mySwap(int* a, int* b) {
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

void myStampaVettori(int arr[], int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		if (i < len - 1) {
			printf("%d, ", arr[i]);
		}
		else {
			printf("%d", arr[i]);
		}
	}
	printf("]");
}

int myRiempiVettori(int arr[], int dim) {
	int n, len = 0;
	do {
		printf("Inserire un numero: ");
		scanf("%d", &n);
		if (n != 0 && len < dim) {
			arr[len] = n;
			len++;
		}

	} while (len < dim && n != 0);
	return len;
}

int myRemoveDuplicates(int arr[], int len1, int noDupl[]) {
	int len2 = 1, i, j;
	noDupl[0] = arr[0];
	for (i = 1; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (arr[i] == noDupl[j]) {
				break;
			}
			else if (j == len2 - 1) {
				noDupl[len2] = arr[i];
				len2++;
			}
		}
	}
	return len2;
}

int myRicercaValori(int arr[], int len, int x) {
	int i;
	for (i = 0; i <= len; i++) {
		if (i == len) {
			return -1;
		}
		else if (arr[i] == x) {
			return i;
		}
	}
}

void strConSpazi(char* stringa, int dim) {
	int c;
	int i = 0;

	while ((c = getchar()) != '\n' && c != EOF && i < dim - 1) {
		stringa[i++] = c;
	}

	stringa[i] = '\0';
}

//funzioni da inserire:
//
//	vari tipi di sorting algorithms
//
//da ricordare all'esame:
//	
//	quando apri i file controlla se il puntatore non sia nullo
//	chiudi sempre i file aperti
//
//	quando allochi della memoria dinamicamente ricorda di liberarla anche alla fine di
//	ogni funzione