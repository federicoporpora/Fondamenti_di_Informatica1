#include <stdio.h>

/*
	Realizzare un programma che, presi in input 2 operandi reali e un operatore (+, -, *, /), esegua l’operazione stampandone il risultato
	Nel caso in cui l’operatore sia errato o l’operazione non eseguibile, si stampi “undefined”
	Suggerimento: utilizzare il costrutto switch
	• il comportamento del programma è determinato in base al valore del carattere “operatore”
*/

int main() {

	float x, y;
	char op;

	printf("\nInserire due numeri e l'operatore (con spazi): ");
	scanf_s("%f %f", &x, &y);
	printf("Inserire l'operatore: ");
	scanf_s(" %c", &op, 1);

	switch (op) {
	case '+':
		printf("Il risultato dell'operazione e' %f\n", x + y); break;
	case '-':
		printf("Il risultato dell'operazione e' %f\n", x - y); break;
	case '*':
		printf("Il risultato dell'operazione e' %f\n", x * y); break;
	case '/':
		if (y != 0) {
			printf("Il risultato dell'operazione e' %f\n", x / y); break;
		}
		else {
			printf("pippozzo hai diviso per 0\n"); break;
		}
	default:
		printf("zio hai sbagliato operatore\n");

	}

	return 0;

}