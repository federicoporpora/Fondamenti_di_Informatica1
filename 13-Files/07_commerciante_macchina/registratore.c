#include "registratore.h"
#include <string.h>

void copy(FILE* source, FILE* dest, char* name, int* result) {
	*result = 0;
	Transaction temp;
	while (fread(&temp, sizeof(Transaction), 1, source) > 0) {
		if (strcmp(temp.customer, name) == 0) {
			fprintf(dest, "%f ", temp.value);
			(*result)++;
		}
	}
	fprintf(dest, "\n");
}