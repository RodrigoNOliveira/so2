#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM_THREADS 10 /*cria 10 threads distintas*/

  int sum; /* esses dados são compartilhados pelo(s) thread(s) */

  void *runner(void *param); /* os threads chamam essa função */

  int main(int argc, char *argv[]){

      srand( time(NULL));

      pthread_t workers[NUM_THREADS];       /* os identificadores das threads */
  
      pthread_attr_t attr; /* conjunto de atributos do thread */
  

  if (argc != 2){
      fprintf(stderr, "usage: a.out <integer value>\n");
      return -1;
  }


  if (atoi(argv[1]) < 0){
      fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
      return -1;
  }



  /* obtém os atributos default */
  pthread_attr_init(&attr);
  


  /* cria as threads */
  int i = 0;
  int valor = 0;
  for (i = 0; i <NUM_THREADS; i++){
    
    pthread_create(&workers[i], &attr, runner,argv[1]);
  }
  
  


  /* espera o thread ser encerrado */
  for (i = 0; i <NUM_THREADS; i++){
     pthread_join(workers[i], NULL);
  }
   


    printf("Programa principal encerrando ...\n");
    //printf("sum = %d\n", sum);
}


  /* O thread assumirá o controle nessa função */
  void *runner(void *param){

    int i, upper = atoi(param);

    sum = 0;
    upper = 1  + (rand () %100);
    if (upper>0){
    for (i = 1; i <= upper; i++){
      sum += i;}
    }
      printf("Resultado da tarefa: (upper = %3d) %4d\n", upper, sum);
    pthread_exit(0);

}
