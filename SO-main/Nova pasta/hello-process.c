#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid = fork();    // criando um processo filho!
    if ( pid < 0 ) {
        // erro na criação do processo filho....
        fprintf(stderr, "Erro na criação do processo");
        return 1; // programa finaliza com erro
    }
    if ( pid == 0 ) {
        // processo filho sendo executado !
        printf("Iniciando comando do SO...\n");
        execlp("/bin/ls", "ls", NULL);
        printf("esta linha é do processo filho.....\n");
    } else {
        // processo pai sendo executado !
        wait();
        printf("Processo filho terminou...\n");
    }
    // trecho de código-fonte em comum (ao pai e ao filho)
    printf("Programa finalizando...\n");
    return 0; // programa finaliza corretamente
}

