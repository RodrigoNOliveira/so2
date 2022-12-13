#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;


	pid = fork();

	if (pid<0){ /* um erro ocorreu */
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if(pid ==0){ /*processo filho*/
		printf("Codigo do filho executando ...\n");
		execlp("/bin/ls","ls",NULL);
		printf("pricessi filho ainda executando ...\n");
	}
	else { /*processo pai*/
		/*o pai esperara que o filho seja concluido*/
		printf("processo pai vai esperar o filho terminar\n");
		wait(NULL);
		printf("Processo filho terminou! \n");
	}
	return 0;
}
