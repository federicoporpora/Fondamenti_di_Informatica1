#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>
#define DIM 10

int myRiempiVettori(int arr[], int dim);
int* trovaSottoArray(int v[], int size, int first, int last, int* dim);

int main() {

    int arr[DIM], len, first, last, lenSA, risultato;

    len = myRiempiVettori(arr, DIM);

    printf("Inserire il primo intero del sotto-array: ");
    scanf("%d", &first);

    printf("Inserire l'ultimo intero del sotto-array: ");
    scanf("%d", &last);

    risultato = trovaSottoArray(arr, len, first, last, &lenSA);

    printf("%d", risultato);

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

int* trovaSottoArray(int v[], int len, int first, int last, int* dim) {
    int i, start_indice = 0, end_indice = 0;

    for (i = 0; i < len; i++) {
        if (v[i] == first) {
            start_indice = i;
            break;
        }
    }

    for (i = 0; i < len; i++) {
        if (v[i] == last) {
            end_indice = i;
            break;
        }
    }

    *dim = end_indice - start_indice + 1;

    return &v[start_indice];
}