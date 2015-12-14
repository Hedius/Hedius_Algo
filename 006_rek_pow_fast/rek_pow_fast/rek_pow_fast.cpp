// rek_ggt.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
/*
Aufgabe: rek_fast_pow.c
--------------------------------------------------------------------------------
pow (x,n) = wenn n gerade:
			ret= pow (x,n/2)
			ret*= ret
			oder sonst
pow (x,n) = wenn n ungerade
			ret= pow (x,n/2)
			ret*= ret
			ret*= x
*/

#include "stdafx.h"
#include <stdio.h>

int rek_pow_fast(int x, int n);

int main()
{
	int x, n;

	printf("X:");
	scanf("%i", &x);
	fflush(stdin);
	printf("N:");
	scanf("%i", &n);

	printf("%i\n", rek_pow_fast(x, n));

	return 0;

}

int rek_pow_fast(int x, int n) {
int ret;
    if(n > 0){
        if(n % 2 == 0){
            ret = rek_pow_fast(x, n / 2);
            ret *= ret;
        }else{
            ret = rek_pow_fast(x, n / 2);
            ret *= ret;
            ret *= x;
        }
    }else{
        return 1;
    }
    return ret;
}