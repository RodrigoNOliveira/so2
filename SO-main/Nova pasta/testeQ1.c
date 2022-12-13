#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>



// void lista(void){
// 	/home/rodrigo ls
// }






int main() {
	pid_t pid;       
	pid = fork();
		if (pid < 0){
		fprintf(stderr, "erro");
		return 1;
		} 
		if (pid == 0){
		system("ls *.txt | wc -l" );
		} else {
              // ?????
         }
return 0;
}
