/**
* myBubbleSort.c

1.2.  Aufgabe: myBubbleSort
Schreiben Sie eine Sortierfunktion, die beliebige Arrays sortieren kann.
void myBubbleSort(void* a, int nelements, int nsize, int (*comp)(const void*, const void*));

Hinweis: siehe: memcpy(), malloc(), free()
Testen Sie ihre Funktion mit dem folgenden Test-Programm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct pers {
	int persnr;
	char name[80 + 1];
} TPERSON;


// sort function
void myBubbleSort(void* a, int nelements, int nsize, int(*comp)(const void*, const void*));

// compare function



#define ANZ 5
int main(int argc, char *argv[]) {
	int a[ANZ];

	int i;

	TPERSON wir[5] = { { 23, "Geher" },{ 3, "Singer" },{ 23, "Bierer" },
	{ -23, "Maurer" },{ 93, "Ziegler" } };


	srand(time(NULL));
	for (i = 0; i < ANZ; i++)
		a[i] = rand() % 100;


	myBubbleSort(a, ANZ, sizeof(a[0]), (int(*)(const void*, const void*)) vergleiche);

	printf("\nINT Array sortiert ************************************\n");
	for (i = 0; i < ANZ; i++)
		printf("%d ", a[i]);
	printf("\n");



	myBubbleSort(wir, ANZ, sizeof(wir[0]),
		(int(*)(void*, void*)) vergleiche_persnr);

	printf("\nPERSON nach persnr sortieren  *************************\n");
	for (i = 0; i < ANZ; i++)
		printf("%3d %s\n", wir[i].persnr, wir[i].name);

	printf("\n");

	return 0;
}

void myBubbleSort(void* a, int nelements, int nsize, int(*comp)(const void*, const void*)) {
	int i;
	int fertig;
	int cmp;
	char *h = (char*)malloc(nsize);
	while (fertig == 0) {
		fertig = 1;

		for (i = 0; i< nelements - 1; i++) {
			cmp = (*comp)(a[i],a[i+1])
			if (cmp>0) {//tauschen
				h = a[i];
				a[i] = a[i + 1];
				a[i+1] = h;

				fertig = 0;
			
			}
		}
	
	free(h);
}