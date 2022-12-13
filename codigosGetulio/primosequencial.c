#include <stdio.h>
#include <stdlib.h>

void mostrar_primos(int m, int n);
int qtd_divisores( int n );

int main(int argc, char *argv[]) {
	
	
	
	mostrar_primos(1, 10);
	
	return 0;
}

/* 
 * mostra a sequencia de números primos no intervalo [n, m]
 */
void mostrar_primos(int m, int n) {
	int i =0;
	for( i = m; i <= n; i++) {
		if ( qtd_divisores( i ) <= 2 ) {
			printf(" %d ", i);
		}
	}	
}

/**
 * retorna a quantidade de divisores de X
 */
int qtd_divisores( int x ) {
	int j = 1;
	int s = 0;  // quantidade de divisores de X
	for( j = 1; j <= x; j++) {
		if ( (x % j) == 0 ) {
			s = s + 1;
		}
	}
	return s;
}
