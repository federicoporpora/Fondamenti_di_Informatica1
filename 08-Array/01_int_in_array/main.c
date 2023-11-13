#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define DIM 10

int main() {

    int counter = 0;
    int n;
    int values[DIM];

    do {
        printf("Inserire un numero: ");
        scanf("%d", &n);
        if (n != 0 && counter < DIM) {
            values[counter] = n;
            counter++;
        }
        
    } while (counter < DIM && n != 0);

    for (int i = 0; i < counter - 1; i++) {
        if (values[i] == values[i + 1]) {
            printf("%d", values[i]);
        }
    }

    return 0;

}