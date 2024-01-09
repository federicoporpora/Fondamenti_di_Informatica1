#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"
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

char* leggi_fino_a(FILE* file, char carattere) {
	int dimensione_buffer = 100; // Dimensione iniziale del buffer
	int posizione = 0; // Posizione attuale nel buffer
	char* buffer = (char*)malloc(dimensione_buffer * sizeof(char)); // Allocazione iniziale del buffer

	if (buffer == NULL) {
		return NULL; // Errore di allocazione
	}

	char c;
	while ((c = fgetc(file)) != carattere && c != EOF) {
		if (posizione >= dimensione_buffer - 1) {
			// Se raggiungiamo la fine del buffer, riallochiamo il buffer con una dimensione maggiore
			dimensione_buffer *= 2;
			char* temp = (char*)realloc(buffer, dimensione_buffer * sizeof(char));
			if (temp == NULL) {
				free(buffer);
				return NULL; // Errore di riallocazione
			}
			buffer = temp;
		}
		buffer[posizione++] = c;
	}

	buffer[posizione] = '\0'; // Terminatore della stringa

	// Rialloca la memoria per adattarla alla dimensione effettiva della stringa
	char* risultato = (char*)malloc((posizione + 1) * sizeof(char));
	if (risultato == NULL) {
		free(buffer);
		return NULL; // Errore di allocazione
	}

	// Copia il contenuto dal buffer alla stringa risultato
	for (int i = 0; i <= posizione; i++) {
		risultato[i] = buffer[i];
	}

	free(buffer); // Libera il buffer temporaneo

	return risultato;
}

FILE* aperturaFile(const char* fileName, const char* openingMode) {
	FILE* fp = fopen(fileName, openingMode);
	if (fp == NULL) {
		perror("Il file non esiste.");
		exit(1);
	}
	return fp;
}

char* inputStringa(const char* frase, int* len) {
	printf("%s ", frase);

	printf("Inserisci una stringa: ");

	// Allocazione iniziale del buffer
	int buffer_size = 100; // Dimensione iniziale del buffer
	char* input = (char*)malloc(buffer_size * sizeof(char));
	if (input == NULL) {
		printf("Errore di allocazione di memoria.\n");
		return NULL;
	}

	int posizione = 0;
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		input[posizione++] = c;
		if (posizione >= buffer_size - 1) {
			// Se raggiungiamo la fine del buffer, riallochiamo il buffer con una dimensione maggiore
			buffer_size *= 2;
			char* temp = (char*)realloc(input, buffer_size * sizeof(char));
			if (temp == NULL) {
				free(input);
				printf("Errore di riallocazione di memoria.\n");
				return NULL;
			}
			input = temp;
		}
	}

	input[posizione] = '\0'; // Terminatore della stringa

	// Rialloca la memoria per adattarla alla dimensione effettiva della stringa
	char* nuova_stringa = (char*)malloc((posizione + 1) * sizeof(char));
	if (nuova_stringa == NULL) {
		free(input);
		printf("Errore di allocazione di memoria.\n");
		return NULL;
	}

	strcpy(nuova_stringa, input); // Copia la stringa input nella nuova stringa
	*len = posizione; // Lunghezza della nuova stringa

	free(input); // Libera il buffer temporaneo

	return nuova_stringa;
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