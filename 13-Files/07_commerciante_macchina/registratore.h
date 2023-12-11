#include <stdio.h>
#define DIM 129

typedef struct {
	char customer[DIM];
	int transactionId;
	float value;
} Transaction;

void copy(FILE* source, FILE* dest, char* name, int* result);