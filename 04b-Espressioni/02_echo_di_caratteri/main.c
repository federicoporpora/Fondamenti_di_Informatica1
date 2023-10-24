#include <stdio.h>

int main()
{

	char c1, c2, c3;
	printf("Inserire 3 caratteri (con spazio): ");
	scanf_s("%c %c %c", &c1, 1, &c2, 1, &c3, 1);
	printf("I caratteri sono %c, %c e %c", c1, c2, c3);

	return 0;

}