// rek_ggt.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
/*Aufgabe: rek_pow.c
----------------------------------------------------------------
pow (x,n) = 1, wenn n==0
			oder sonst
pow (x,n) = x * pow(x,n-1)

*/

#include "stdafx.h"
#include <stdio.h>

int rek_pow(int x, int n);

int main()
{
	int x, n;

	printf("X:");
	scanf("%i", &x);
	fflush(stdin);
	printf("N:");
	scanf("%i", &n);

	printf("%i\n", rek_pow(x, n));


	return 0;
}

int rek_pow(int x, int n) {
	if (n == 0) {
		return 1;
	}
	return x*rek_pow(x, n - 1);
}