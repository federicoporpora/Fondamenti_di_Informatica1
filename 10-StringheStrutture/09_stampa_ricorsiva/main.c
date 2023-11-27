#define _CRT_SECURE_NO_DEPRECATE

/*
    Scrivere una procedura ricorsiva:
        void printchar(char stringa[])
    che stampi, ricorsivamente, tutti i caratteri contenuti in stringa, un carattere per linea,
    assumendo che stringa sia ben formata.
*/

#include <stdio.h>

void printchar(char stringa[]);

int main() {

    char stringa[20] = "puppa";

    printchar(stringa);

    return 0;

}

void printchar(char stringa[]) {
    if (stringa[0] != '\0') {
        printf("%c\n", stringa[0]);
        printchar(&stringa[1]);
    }
}