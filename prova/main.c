#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void swap(int* a, int* b);

int main() {

	int a = 1;
	int b = 2;

	printf("prima dello scambio: a == %d, b == %d", a, b);
	swap(&a, &b);
	printf("dopo lo scambio: a == %d, b == %d", a, b);

	return 0;

}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}