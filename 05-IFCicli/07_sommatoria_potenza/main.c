#define _CRT_SECURE_NO_DEPRECATE

/*
	Si realizzi un programma che, partendo da una base a ed un limite n, calcoli la seguente funzione: (sommatoria da i = 0 a n di a alla i)
	Realizzare il programma in due modi diversi:
	1.Utilizzando due cicli (uno per la sommatoria, ed uno per la potenza)
	2.Utilizzando un ciclo solo
*/

#include <stdio.h>

int main()
{

	int a, n;
	int i = 1;
	int sum = 1;

	printf("Inserire la base della potenza (a) ed il limite della sommatoria (n): ");
	scanf("%d%d", &a, &n);

	int prod = 1;

	while (i <= n) {
		while (i <= n) {
			prod *= a;
			i += 1;
		}
		sum += prod;
		i = 1;
		n -= 1;
		prod = 1;
	}

	printf("Il risultato della sommatoria e' %d", sum);

	return 0;

}