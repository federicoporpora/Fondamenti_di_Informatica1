#define _CRT_SECURE_NO_DEPRECATE

/*
    Creare un programma che legga da input una sequenza di interi, di lunghezza non nota
    a priori (al più 10), e terminata da 0. A tal scopo, si realizzi una funzione che riceva
    come parametri di ingresso un vettore e la sua dimensione fisica, e restituisca la dimensione logica del
    vettore. Tale funzione si deve fare carico della fase di lettura e riempimento dell’array.
    La sequenza può contenere elementi ripetuti (anche più volte).
    Si realizzi una funzione che, ricevuti un array e la sua dimensione, ed un elemento da cercare,
    restituisca il valore -1 se l’elemento non è presente nell’array; altrimenti restituisca il primo
    indice in cui è presente l’elemento cercato.
    Si realizzi un main che invochi le funzioni, e che stampi a video tutti gli elementi del primo
    vettore che NON compaiono nel secondo.
*/

#include <stdio.h>
#define DIM 10

int myRiempiVettori(int arr[], int dim);
int myRicercaValori(int arr[], int len, int x);
void myStampaVettori(int arr[], int len);
int myRemoveDuplicates(int arr[], int len1, int noDupl[]);

int main() {

    int arr1[DIM], arr2[DIM], arrF[DIM], noDupl[DIM], len1, len2, lenF = 0, lenNoDupl, i;

    printf("Prima sequenza di interi:\n");
    len1 = myRiempiVettori(arr1, DIM);

    printf("\nSeconda sequenza di interi:\n");
    len2 = myRiempiVettori(arr2, DIM);

    for (i = 0; i < len1; i++) {
        if (myRicercaValori(arr2, len2, arr1[i]) == -1) {
            arrF[lenF] = arr1[i];
            lenF++;
        }
    }

    lenNoDupl = myRemoveDuplicates(arrF, lenF, noDupl);

    myStampaVettori(noDupl, lenNoDupl);

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