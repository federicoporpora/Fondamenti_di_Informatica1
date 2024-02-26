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

//void scambia(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

int trovaPosMax(int v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++)
		if (v[posMax] < v[i]) posMax = i;
	return posMax;
}

void naiveSort(int v[], int n) {
	int p;
	while (n > 1) {
		p = trovaPosMax(v, n);
		if (p < n - 1) scambia(&v[p], &v[n - 1]);
		n--;
	}
}

void bubbleSort(int v[], int n) {
	int i, ordinato = 0;
	while (n > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < n - 1; i++)
			if (v[i] > v[i + 1]) {
				scambia(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		n--;
	}
}

void insOrd(int v[], int pos) {
	int i = pos - 1, x = v[pos];
	while (i >= 0 && x < v[i]) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x; /* inserisce l’elemento */
}

void insertSort(int v[], int n) {
	int k;
	for (k = 1; k < n; k++)
		insOrd(v, k);
}

void merge(int v[], int i1, int i2, int fine, int vout[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}

void mergeSort(int v[], int first, int last, int vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}

//void quickSortR(int a[], int iniz, int fine)
//{
//	int i, j, iPivot, pivot;
//	if (iniz < fine)
//	{
//		i = iniz;
//		j = fine;
//		iPivot = fine;
//		pivot = a[iPivot];
//		do /* trova la posizione del pivot */
//		{
//			while (i < j && a[i] <= pivot) i++;
//			while (j > i && a[j] >= pivot) j--;
//			if (i < j) scambia(&a[i], &a[j]);
//		} while (i < j);
//		/* determinati i due sottoinsiemi */
// /* posiziona il pivot */
//		if (i != iPivot && a[i] != a[iPivot])
//		{
//			scambia(&a[i], &a[iPivot]);
//			iPivot = i;
//		}
//		/* ricorsione sulle sottoparti, se necessario */
//		if (iniz < iPivot - 1)
//			quickSortR(a, iniz, iPivot - 1);
//		if (iPivot + 1 < fine)
//			quickSortR(a, iPivot + 1, fine);
//	} /* (iniz < fine) */
//}
//
//void quickSort(int a[], int dim)
//{
//	quickSortR(a, 0, dim - 1);
//}

int contaRighe(FILE* fp) {
	int righe = 0;
	char carattere;

	// Legge il file carattere per carattere fino alla fine del file
	while ((carattere = fgetc(fp)) != EOF) {
		if (carattere == '\n') {
			righe++;
		}
	}

	// Conteggio finale della riga se il file non termina con un newline
	if (carattere != '\n' && righe != 0) {
		righe++;
	}

	rewind(fp);

	return righe;
}

//da ricordare all'esame:
//	
//	quando apri i file controlla che il puntatore non sia nullo
//	chiudi sempre i file aperti
//
//	quando allochi della memoria dinamicamente ricorda di liberarla (anche alla fine di ogni funzione)
//
//	dealloca correttamente le liste alla fine dei file

// MAIN MAIN TEMPLATE (ANCHE PER FILE FUNZIONI)

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include "list.h"
//#include "myLib.h"
//
//int main() {
//
//
//	return 0;
//}

// FUNZIONE SOSTITUTIVA DI > NELLE STRUTTURE (PER ALGORITMI DI ORDINAMENTO) (DA MODIFICARE IN OGNI CASO)

//int isGreaterThan(Foto a, Foto b) {
//	// Se gli interi sono uguali, confronto la prima stringa
//	int firstStrCompare = strcmp(a.nome, b.nome);
//
//	if (firstStrCompare > 0) {
//		return 1;
//	}
//	else if (firstStrCompare < 0) {
//		return 0;
//	}
//	else if (a.id >= b.id) {
//		return 1;
//	}
//	else if (a.id < b.id) {
//		return 0;
//	}
//}

// FUNZIONE TEMPLATE PER LEGGERE DATI DA TESTO E METTERLI IN VETTORE DI STRUTTURE ALLOCATO DINAMICAMENTE

//struct* leggiStruct(char* fileName, int* dim) {
//	FILE* fp;
//	struct* result;
//	struct temp;
//	int count;
//	*dim = 0;
//	result = NULL;
//	fp = fopen(fileName, "rt");
//	if (fp != NULL) {
//		count = contarighe(fp);
//		if (count > 0) {
//			result = (struct*)malloc(sizeof(struct) * count);
//			while (fscanf(fp, "%d%s", &(temp.intero), temp.stringa) == 2) {
//				result[*dim] = temp;
//				(*dim)++;
//			}
//		}
//		fclose(fp);
//	}
//	return result;
//}

// FUNZIONE TEMPLATE PER LEGGERE DATI DA TESTO E METTERLI IN LISTA

//list leggiStruct(char* fileName) {
//	FILE* fp;
//	list result;
//	struct temp;
//	result = emptylist();
//	fp = fopen(fileName, "rt");
//	if (fp != NULL) {
//		while (fscanf(fp, "%d%s", &(temp.intero), temp.stringa) == 2)
//			result = cons(temp, result);
//		fclose(fp);
//	}
//	return result;
//}