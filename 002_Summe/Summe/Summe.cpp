// Summe.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>

int summe(int n);

int main()
{

	int zahl, i;

	printf("\nSumme (rekursiv)");
	do {
		printf("\nBitte eine pos. Zahl: ");
		scanf("%i", &zahl);
	} while (zahl < 0);

	printf("Summe: %i", summe(zahl));

	putchar('\n');
	return 0;
}

int summe(int n) {
	if (n>1) {
		return n + summe(n - 1);
	}
	return n;
}