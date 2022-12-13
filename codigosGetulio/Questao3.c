#include <pthread.h> /* cria��o de threads */
#include <stdio.h>   /* impress�o na tela */
#include <stdlib.h>  /* biblioteca padr�o ( atoi ) */
#include <time.h>    /* para a semente aleat�ria */
#include <math.h>

typedef struct _dados {
	
	double * conjunto;     // conjunto de dados
	int tamanho_conjunto;  // tamanho do conjunto
} Dados;

double * dummy( int n );

 

void *varianca(void * param);
void *runner(void * param); /* o thread */
void *desvio(void * param);
void *mediana(void * param);

double result, res;


int main(int argc, char *argv[]){
	
	srand( time(NULL) ); // "semente" para gera��o de n�meros aleat�rios
	
	pthread_t tid;   
	pthread_t tid1; 
	pthread_t tid2;  
	pthread_t tid3;    /* o identificador do thread */
	pthread_attr_t attr; /* configura��o de atributos do thread */
	
	// ======================================
	// verifica��o dos parametros de entrada
	if (argc != 2) {
		fprintf(stderr,"usage: a.out <integer value>\n argc=%d\n", argc);
		return 1024;
	}

	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
		return 2048;
	}

	// ======================================
	
	// prepara��o dos dados para a thread
	Dados * d = (Dados *) malloc( sizeof(Dados) );

	
	d->tamanho_conjunto = atoi(argv[1]);
	d->conjunto = dummy( d->tamanho_conjunto );
	
	/* captura os atributos padr�o */
	pthread_attr_init(&attr);

	/* cria o thread */
	pthread_create(&tid,&attr,runner, (Dados *) d);
	pthread_create(&tid3,&attr,varianca,(Dados *) d);
	pthread_create(&tid1,&attr,mediana, (Dados *) d);
	pthread_create(&tid2,&attr,desvio, (Dados *) d);
	

	/* agora espera o thread terminar */
	pthread_join(tid,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	

	
	

	printf("\nPrograma finalizado\n");
	
	free( d ); // libera��o do "pacote" de dados para a thread
	return 0;
}

/**
  * O thread assumir� o controle nessa fun��o
 */
void *runner(void * param) {
	
	Dados * x = (Dados *) param;

	printf("\nTamanho do conjunto: %d\n", x->tamanho_conjunto);
	int i = 0;
	for(i = 0; i < x->tamanho_conjunto; i++) {
		printf(" %g ", x->conjunto[i]);
	}
    
	
	
	pthread_exit(0);
}


void *mediana(void * param) {
	
	Dados * x = (Dados *) param;	
	int aux;
	for( int i = 0; i< x->tamanho_conjunto; i++){
        for(int j=i+1; j<x->tamanho_conjunto; j++){
            if(x->conjunto[i]>x->conjunto[j]){
                aux=x->conjunto[i];
                x->conjunto[i] = x->conjunto[j];
                x->conjunto[j] = aux;
            }
        }
    }

    double tam = (x->tamanho_conjunto/2)-0.5;
    int b = tam;
    if ((x->tamanho_conjunto%2) == 0){
        res =(double)(x->conjunto[b] +x->conjunto[b+1])/2;
        
    } else{
        res= x->conjunto[(int)tam];
    }
    
	printf("\nA mediana é de: %g\n", res);
	
	
	pthread_exit(0);
}


void *varianca(void * param){
		Dados * x = (Dados *) param;

	int b = 0;
	double soma = 0;
	for( b=0 ; b < x->tamanho_conjunto; b++) {
		soma+= x->conjunto[b];
	}
	result = soma/x->tamanho_conjunto;
    double vari = 0;
	 for ( int i = 0; i < x->tamanho_conjunto; i++)
    {
        vari = vari + pow((x->conjunto[i] - result),2);
    }
	vari = (vari/(x->tamanho_conjunto-1));
	printf("\nA varianca é de: %g\n", vari);
	
	
	pthread_exit(0);
}


void *desvio(void * param) {
	Dados * x = (Dados *) param;
	double desv = 0;
	int b = 0;
	double soma = 0;
	for( b=0 ; b < x->tamanho_conjunto; b++) {
		soma+= x->conjunto[b];
	}
	result = soma/x->tamanho_conjunto;
    double vari = 0;
	 for ( int i = 0; i < x->tamanho_conjunto; i++)
    {
        vari = vari + pow((x->conjunto[i] - result),2);
    }
	
	desv = sqrt(vari/ (x->tamanho_conjunto-1));
	
	printf("\nO desvio-padrão é de: %g\n", desv);
	
	pthread_exit(0);
}

 

/**
 * gera dados aleatorios para testes
 */
double * dummy( int n ) {
	double * v = (double *) malloc( n * sizeof( double ) );
	int i;
	for(i = 0; i < n; i++) {
		v[i] = rand() % 100;
	}
	return v;
}
