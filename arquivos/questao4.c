#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>

int Primo(int x);
void *runner(void *param); /* os threads chamam essa função */

int main(int argc, char *argv[]){

      pthread_t tid;       /* o identificador do thread */
  
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

   printf("Os números primos existentes até %d: \n", atoi(argv[1]));

  /* cria o thread */
  pthread_create(&tid, &attr, runner, argv[1]);
  
  /* espera o thread ser encerrado */
  pthread_join(tid, NULL);
  
 

}


 void *runner(void *param){
	

    int x = atoi(param), i;
        for (int i = 1; i <= x; i++){
            if(Primo(i) <= 2){
                printf("%i ", i);
            }
        }    
pthread_exit(0);
    
}
 
int Primo(int x){
    int result = 0;
    for (int i = 1; i <= x ; i++) {
            if (x % i == 0) {
                result++; 
            }
}
    return result;
}



