#include <stdio.h>

/*
	Realizzare un programma che legga da input quattro float rappresentanti i quattro voti.
	Il programma controlli che ogni voto sia compreso nel range (10).
	In caso contrario, il programma termini.
	Il programma stampi il punteggio finale, dato come media dei tre voti più bassi
*/

int main() {

	float a, b, c, d, max, final_vote;

	printf("Inserire 4 voti (con spazio): ");
	scanf_s("%f %f %f %f", &a, &b, &c, &d);

	if ((a > 10) || (b > 10) || (c > 10) || (d > 10)) {
		printf("Il voto da te inserito e' troppo alto, il massimo e' 10.");
	}
	else {
		max = (a > b) ? a : b;
		max = (max > c) ? max : c;
		max = (max > d) ? max : d;

		final_vote = (a + b + c + d - max) / 3;

		printf("La media dei tre voti piu' bassi e': %f", final_vote);
	}

	return 0;

}