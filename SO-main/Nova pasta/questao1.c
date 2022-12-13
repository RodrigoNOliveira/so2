#include <stdio.h>
#include <unistd.h>
int main() {
	int i;
        for (i = 0; i < 4; i++) {
 		fork();
	printf("Processo pai: %u  /   Processo filho: %u\n", getppid(), getpid());
                             // ?????
	}

        return 0;
}
