#include <stdio.h>
#include <stdlib.h>

//void mostrar_primos(int m, int n);
//int qtd_divisores( int n );

double media();
int vet[5] = { 4, 5 ,6 ,7 ,3};
double result = 0;
int menor, maior;

int main(int argc, char *argv[]) {
	
	int i;

	
	printf("Os valores do vetor e de:");
	
	for(i = 0; i < 5; i++){
		printf(" %d", vet[i]);
	}
	

	printf("\nA media e de: %g" , media());
	printf("\nO menor valor e de: %d" , minimo());
	printf("\nO maior valor e de: %d" , max());
	
	
	return 0;
}



double media() {
	int x = 0;
	double soma = 0;

	
	for( x=0 ; x < 5; x++) {
		soma+= vet[x];
	}

	result = soma/5;

	return result;
}

int minimo() {
	int x;
	menor = vet[0];
	for( x=0 ; x < 5; x++) {
		if (menor > vet[x]){
			menor=vet[x];
		}
	}
	return menor;
}

int max() {
	int x;
	maior = vet[0];
	for( x=0 ; x < 5; x++) {
		if (maior < vet[x]){
			maior=vet[x];
		}
	}
	return maior;
}
