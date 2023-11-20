#define _CRT_SECURE_NO_DEPRECATE

/*

*/

#include <stdio.h>
#define DIM 10

int myRiempiVettori(int arr[], int dim);
void myStampaCresc(int arr1[], int len1, int arr2[], int len2);

int main() {

	int arr1[DIM], len1, arr2[DIM], len2;

	printf("Prima sequenza di interi:\n");
	len1 = myRiempiVettori(arr1, DIM);

	printf("\nSeconda sequenza di interi:\n");
	len2 = myRiempiVettori(arr2, DIM);

	myStampaCresc(arr1, len1, arr2, len2);

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

void myStampaCresc(int arr1[], int len1, int arr2[], int len2) {
	int i, j;
	i = j = 0;

	while (i < len1 && j < len2) {
		if (arr1[i] < arr2[j]) {
			printf("%d ", arr1[i]);
			i++;
		}
		else {
			printf("%d ", arr2[j]);
			j++;
		}
	}
	while (i < len1) {
		printf("%d ", arr1[i]);
		i++;
	}
	while (j < len2) {
		printf("%d ", arr2[j]);
		j++;
	}
}