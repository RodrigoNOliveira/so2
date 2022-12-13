#include <pthread.h> /* cria��o de threads */
#include <stdio.h>   /* impress�o na tela */
#include <stdlib.h>  /* biblioteca padr�o ( atoi ) */
#include <time.h>    /* para a semente aleat�ria */

typedef struct _dados {
	
	double * conjunto;     // conjunto de dados
	int tamanho_conjunto;  // tamanho do conjunto
} Dados;

double * dummy( int n );


void *runner(void * param); /* o thread */
void *maiorN(void * param);
void *men(void * param);
void *conta(void * param);
//double calcula();
int soma( int x );
int maior(int x );
int menor(int x );
double result;

int max, min, r,m ,sum;

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
	pthread_create(&tid3,&attr,conta, (Dados *) d);
	pthread_create(&tid1,&attr,men, (Dados *) d);
	pthread_create(&tid2,&attr,maiorN, (Dados *) d);
	

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

	printf("Tamanho do conjunto: %d\n", x->tamanho_conjunto);
	int i = 0;
	for(i = 0; i < x->tamanho_conjunto; i++) {
		printf(" %g ", x->conjunto[i]);
	}
    
	
	
	pthread_exit(0);
}



void *maiorN(void * param) {
	
	Dados * x = (Dados *) param;
    
	m= x->conjunto[0];
	for (int i = 0; i < x->tamanho_conjunto; i++)
	{
		max = maior(x->conjunto[i]);

	}

	printf("\nO maior entre os valores: %d\n", max);
	
	
	pthread_exit(0);
}

void *men(void * param) {
	
	Dados * x = (Dados *) param;
	m= x->conjunto[0];
	for (int i = 0; i < x->tamanho_conjunto; i++)
	{
		min = menor(x->conjunto[i]);
	}
	
	printf("\nO menor entre os valores: %d\n", min);
	
	
	pthread_exit(0);
}

void *conta(void * param) {
	
	Dados * x = (Dados *) param;
	for (int i = 0; i < x->tamanho_conjunto; i++)
	{
		result = soma(x->conjunto[i]);
	}

	result = result/x->tamanho_conjunto;


	printf("\nA media dos valores é de: %g\n", result);
	
	
	pthread_exit(0);
}

 
int soma( int h ) {
	sum = sum + h;
	return sum;
}
 
 
int maior(int h ) {
	
	if (r < h){
		r = h;
	}
	
	return r;
}

int menor(int f ) {

	if (m > f){
		m = f;
	}
	
	return m;
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
