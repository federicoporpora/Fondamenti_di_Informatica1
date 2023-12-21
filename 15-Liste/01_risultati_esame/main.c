#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

int main(void)
{
	FILE* fp;
	list startList, lowList, highList, temp;
	element voto, soglia;
	if ((fp = fopen("risultati.txt", "r")) == NULL)
	{
		perror("The file does not exist!"); exit(-1);
	}
	startList = emptyList();
	lowList = emptyList();
	highList = emptyList();
	while (fscanf(fp, "%d", &voto) > 0)
		startList = cons(voto, startList);
	fclose(fp);
	showList(startList);
	printf("\nInserire soglia: ");
	scanf("%d", &soglia);

	while (startList != NULL) {
		temp = head(startList);
		if (temp > soglia) {
			highList = cons(temp, highList);
		}
		else {
			lowList = cons(temp, lowList);
		}
		startList = tail(startList);
	}

	printf("\nLista voti superiori a soglia: ");
	showList(highList);
	printf("\nLista voti inferiori a soglia: ");
	showList(lowList);

	freelist(startList);
	freelist(highList);
	freelist(lowList);

    return 0;

}