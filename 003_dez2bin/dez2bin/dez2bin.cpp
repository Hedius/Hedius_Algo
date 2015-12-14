

#include <stdio.h> 

void dez2bin(int n);


int main() {
	int dez;
	
	printf("Dec Zahl: ");
	scanf("%i", &dez);
	printf("Binärwert:");
	dez2bin(dez);
	printf("\n");
	return 0;
}

void dez2bin(int n) {
	int rest;
	int wert=0;
	int faktor = 1;
	if (n != 0) {
		
		rest = n % 2;
		wert = wert + rest*faktor;
		faktor = faktor * 10;
		dez2bin(n / 2);
	}
	printf("%i", wert);
}