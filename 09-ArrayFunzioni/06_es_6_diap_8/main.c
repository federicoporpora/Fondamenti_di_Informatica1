#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input una sequenza di interi, di lunghezza non nota a priori (al più 10),
    e terminata da 0. A tal scopo, si realizzi una funzione che riceva come parametri di ingresso un vettore
    e la sua dimensione fisica, e restituisca la dimensione logica del vettore.
    Tale funzione si deve fare carico della fase di lettura e riempimento dell’array.
    La sequenza può contenere elementi ripetuti (anche più volte).
    Si realizzi una funzione che, ricevuti in ingresso il primo vettore con la sua dimensione logica,
    ed un secondo vettore con la sua dimensione fisica, memorizzi nel secondo vettore tutti gli elementi del primo, ma
    senza ripetizioni. La funzione restituisca la dimensione logica del secondo vettore.
    Si realizzi un main che invochi le funzioni, e che stampi a video l’elenco degli elementi non ripetuti
*/

#include <stdio.h>
#define DIM 10

int myRiempiVettori(int arr[], int dim);
int myRemoveDuplicates(int arr[], int len1, int noDupl[]);
void myStampaVettori(int arr[], int len);

int main() {

	int arr[DIM], noDupl[DIM], len1, len2;

	len1 = myRiempiVettori(arr, DIM);

	len2 = myRemoveDuplicates(arr, len1, noDupl, DIM);

	printf("len1: %d, len2: %d, noDupl: ", len1, len2);
	myStampaVettori(noDupl, len2);

    return 0;

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