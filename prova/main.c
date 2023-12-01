#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {

	char ago[10] = "puppa";
	char pagliaio[50] = "pupupupupupupupupupupupupupupupupupuppa";

	printf("%d", strStr(pagliaio, ago));

	return 0;

}

int strStr(char* haystack, char* needle) {
	long long i, j = 0;
	for (i = 0; i <= strlen(haystack); i++) {
		if (i == strlen(haystack)) {
			return -1;
		}
		if (haystack[i] == needle[0]) {
			while (j <= strlen(needle)) {
				if (j == strlen(needle)) {
					return i;
				}
				if (needle[j] == haystack[i + j]) {
					j++;
				}
				else { break; }
			}
		}
	}
}