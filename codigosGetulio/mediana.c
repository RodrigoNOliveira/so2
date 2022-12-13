#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Max 6
//void mostrar_primos(int m, int n);
//int qtd_divisores( int n );

int vet[Max] = {29, 32, 35, 49, 57, 80};
int i, j;
int aux;
double res;
double result = 0;
double mediana();
double media();
double desvio();
double varianca();



int main(int argc, char *argv[]) {
	
    printf("\nA media é de: %g", media());
    printf("\nA mediana é de: %g", mediana());
    printf("\nO desvio padrão é de: %g", desvio());
    printf("\nA variança é de: %g", varianca());

    return 0;
}


double mediana() {
	
    for( i = 0; i<Max; i++){
        for(j=i+1; j<Max; j++){
            if(vet[i]>vet[j]){
                aux=vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    double tam = Max/2-0.5;
    int x = tam;
    if ((Max%2) == 0){
        res =(double)(vet[x] +vet[x+1])/2;
        
    } else{
        res= vet[(int)tam];
    }
    return res;
}


double varianca(){
    double vari = 0;
    for ( i = 0; i < Max; i++)
    {
        vari = vari + pow((vet[i] - media()),2);
    }
    return (vari/(Max-1));
}

double desvio(){
    double desv = 0;
    desv = sqrt(varianca());
    
    return desv;


}







double media() {
	int x = 0;
	double soma = 0;

	
	for( x=0 ; x < Max; x++) {
		soma+= vet[x];
	}

	result = soma/Max;

	return result;
}
