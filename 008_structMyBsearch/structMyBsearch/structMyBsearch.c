/*
1.  �bungen zum Suchen in Arrays
Bin�re Suche auf Struktur-Arrays in C
Iterative bzw. rekursive Algorithmen
Verwendung der C-Standardbibliothek: bsearch()

1.1.  Aufgabe: structMyBsearch.c (iterativ,rekursiv)
Bringen Sie das folgende Programm zum Laufen.
*/

// structMyBsearch.c
// Name: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int persnr;
	char name[80];
} TPERSON;


// F-decl
// ------------------------------------------------------------------------
TPERSON* myBsearchName(TPERSON* key, TPERSON* a, int left, int right) {
	// gesucht wird nach der Strukturkomponente name
	// wenn key->name im Array a vorhanden ist, wird
	// die Adresse des gefundenen Elementes in a zur�ckgegednben.
	// wenn nicht vorhanden, wird NULL zur�ckgegeben.

	// Algorithmus: bin�re Suche (iterativ)

	
										/* Solange die zu durchsuchende Menge nicht leer ist */
	int m;
	int cmp;

	while (left <= right) {
		m = (left + right) / 2;
		cmp = strcmp(key->name, a[m].name);
		if (cmp==0) {
			return &a[m];
		}
		else if (cmp<0) {
			right = m - 1;
			
		}
		else {
			
			left = m + 1;
		}
	

	}
	return NULL; // NOT FOUNDs
	
}


TPERSON*
myBsearchPersonNrRek(TPERSON* key, TPERSON* a, int left, int right) {
	// gesucht wird nach der Strukturkomponente persnr
	// wenn key->persnr im Array a vorhanden ist, wird
	// die Adresse des gefundenen Elementes in a zur�ckgegeben.
	// wenn nicht vorhanden, wird NULL zur�ckgegeben.

	// Algorithmus: bin�re Suche (rekursiv)
	int m;
	
	
	m = (left + right) / 2;
	if (key->persnr == a[m].persnr) {
		return &a[m];
	}
	else if (left > right) {
		return NULL; //nichts gefunden
	}
	else if (key->persnr > a[m].persnr) {
		return myBsearchPersonNrRek(key, a, m - 1, right);
	}
	else if (key->persnr < a[m].persnr) {
		return myBsearchPersonNrRek(key, a, m + 1, right);
	}
	
}



// main
// --------------------------------------------------------------------
int main() {
	// WEIL die Arrays f�r die bin�re Suche sortiert sein m�ssen,
	//	verwenden wir 2 Arrays:

	TPERSON wirName[5] = {
		{ 23, "Bierer" },
		{ 23, "Geher" },
		{ -23, "Maurer" },
		{ 3, "Singer" },
		{ 93, "Ziegler" }
	};

	TPERSON wirNummer[5] = {
		{ -23, "Maurer" },
		{ 3, "Singer" },
		{ 23, "Geher" },
		{ 23, "Bierer" },
		{ 93, "Ziegler" }
	};

	TPERSON* pgefunden;
	TPERSON search;

	int i;

	//ausgabe
	printf("PERSONS sorted by Name .................\n");
	for (i = 0; i < 5; i++) {
		printf("%5d: <%s>\n", wirName[i].persnr, wirName[i].name);
	}
	printf("\n");

	printf("Enter Name to search: ");
	scanf("%s", search.name);

	pgefunden = myBsearchName(&search, wirName, 0, 4);

	if (NULL == pgefunden) {
		printf("NOT FOUND: <%s> \n", search.name);
	}
	else {
		printf("FOUND: %-5d %s\n", pgefunden->persnr, pgefunden->name);
	}

	// ---------------------------------------------------------------------
	//ausgabe
	printf("\n\nPERSONS sorted by Persnr .................\n");
	for (i = 0; i < 5; i++) {
		printf("%5d: <%s>\n", wirNummer[i].persnr, wirNummer[i].name);
	}
	printf("\n");

	printf("Enter PersNr to search: ");
	scanf("%i", &search.persnr);


	pgefunden = myBsearchPersonNrRek(&search, wirNummer, 0, 4);

	if (NULL == pgefunden) {
		printf("NOT FOUND: Persnr= <%i> \n", search.persnr);
	}
	else {
		printf("FOUND: %-5d %s\n", pgefunden->persnr, pgefunden->name);
	}

	return 0;
}