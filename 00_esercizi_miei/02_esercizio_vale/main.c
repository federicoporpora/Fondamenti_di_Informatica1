#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle);
void strConSpazi(char* stringa, int dim);

int main() {

    char haystack[300];
    
    int location;

    do {
        printf("Inserire la stringa: ");
        strConSpazi(haystack, 300);

        location = strStr(haystack, "salvi");
        if (location == -1) {
            location = strStr(haystack, "Salvi");
        }
        if (location == -1) {
            location = strStr(haystack, "Tommaso");
        }
        if (location == -1) {
            location = strStr(haystack, "tommaso");
        }
        if (location == -1) {
            location = strStr(haystack, "riccioli");
        }
        if (location == -1) {
            location = strStr(haystack, "Riccioli");
        }
        if (location == -1) {
            location = strStr(haystack, "puppa");
            if (location != -1) {
                break;
            }
        }
        

        if (location == -1) {
            printf("non me ne frega un cazzo\n\n");
        }
        else {
            printf("basta pensare a lui\n\n");
        }
    } while (location != -2);

    return 0;

}

int strStr(char* haystack, char* needle) {
    int hay_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len > hay_len) {
        return -1;
    }

    for (int i = 0; i <= hay_len - needle_len; ++i) {
        int j;
        for (j = 0; j < needle_len; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needle_len) {
            return i;
        }
    }

    return -1;
}

void strConSpazi(char* stringa, int dim) {
    int c;
    int i = 0;

    while ((c = getchar()) != '\n' && c != EOF && i < dim - 1) {
        stringa[i++] = c;
    }

    stringa[i] = '\0';
}