/*Aufgabe: rek_ggt.c
----------------------------------------------------------------
ggT (a,b) = a, wenn b==0
			oder 
ggT (a,b) = ggT (b, a%b)

*/

#include "stdafx.h"
#include <stdio.h>

int ggT(int a, int b);

int main()
{
	int a, b;

	printf("A:");
	scanf("%i", &a);
	fflush(stdin);
	printf("B:");
	scanf("%i", &b);
	
	printf("%i\n", ggT(a,b));

    return 0;
}

int ggT(int a, int b) {
	if (b == 0) {
		return a;
	}
	return ggT(b, a%b);
}