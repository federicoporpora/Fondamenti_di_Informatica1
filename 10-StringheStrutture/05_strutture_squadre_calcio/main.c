#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#define DIM 10

typedef struct {
    char name[21];
    int codice, goalFatti, goalSubiti;
} squadra;

int main() {

	int nSquadre, i, codice;
	squadra vSquadre[DIM];

	nSquadre = myRiempiVettori(vSquadre, DIM);

	printf("Tutte le squadre con differenza goal positiva:\n");
	for (i = 0; i < nSquadre; i++) {
		if (vSquadre[i].goalFatti > vSquadre[i].goalSubiti) {
			printf("Nome: %s, codice: %d\n", vSquadre[i].name, vSquadre[i].codice);
		}
	}

	printf("\nOra inserire il codice di una squadra: ");
	scanf("%d", &codice);

	for (i = 0; i < nSquadre; i++) {
		if (codice == vSquadre[i].codice) {
			printf("\nNome squadra: %s\tGoal fatti %d\tGoal subiti %d", vSquadre[i].name, vSquadre[i].goalFatti, vSquadre[i].goalSubiti);
		}
	}

    return 0;

}

int myRiempiVettori(squadra arr[], int dim) {
	int len = 0, n;
	char str[21];
	do {
		printf("Inserire il nome della squadra (per terminare '0'): ");
		scanf("%s", &str);
		if (str	[0] != '0' && len < dim) {
			strcpy(arr[len].name, str);
			printf("Inseire il codice della squadra: ");
			scanf("%d", &n);
			arr[len].codice = n;
			printf("Inseire i goal fatti dalla squadra: ");
			scanf("%d", &n);
			arr[len].goalFatti = n;
			printf("Inseire i goal subiti dalla squadra: ");
			scanf("%d", &n);
			arr[len].goalSubiti = n;
			len++;
		}
	} while (str[0] != '0' && len < dim);
	return len;
}