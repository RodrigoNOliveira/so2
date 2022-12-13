#include <stdio.h>
#include <unistd.h>
int main() {
	pid_t pid;
        int i;       
 for (i = 0; i < 4; i++) { 
	pid = fork();
		if (pid < 0){
		fprintf(stderr, "erro");
		return 1;
		} 
		if (pid == 0){
		printf("Processo filho: %u\n" , getpid());
		} else {
		printf( "Processo pai: %u\n", getpid());
}
              // ?????
         }
return 0;
}
