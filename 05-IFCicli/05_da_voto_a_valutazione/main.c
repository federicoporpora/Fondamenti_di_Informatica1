#include <stdio.h>

/*
	Realizzare un programma che legga da input un voto (carattere tra ‘A’ ed ‘E’) e ne stampi il significato
	(A significa ottimo, E significa gravemente insuff., etc. etc.)
*/

int main() {

	char voto;

	printf("Inserire un voto: ");
	scanf_s("%c", &voto, 1);

	switch (voto) {
	case 'A':
		printf("\nOttimo\n"); break;
	case 'B':
		printf("\nBuono\n"); break;
	case 'C':
		printf("\nSufficiente\n"); break;
	case 'D':
		printf("\nInsufficiente\n"); break;
	case 'E':
		printf("\nGravemente insufficiente\n"); break;
	default:
		printf("\nzio hai sbagliato qualcosa\n");
	}

	return 0;

}