#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {

    int x;
    printf("Inserire un numero ed io diro' se e' palindromo o meno: ");
    scanf("%d", &x);
    printf("%d", isPalindrome(x));

    return 0;

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

int isPalindrome(int x) {
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

int myPow(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}