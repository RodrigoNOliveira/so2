#include <sys/types.h>
#include <sys/wait.h>
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
        printf("Processo filho : %u\n", getpid());
        long count = 0;
        while ( count < 3 ) {
            system("sleep 1");
            count++;
        }
        printf("Processo filho vai finalizar sua atividade: %u \n", getpid() );
    } else {
        // processo pai sendo executado !
        printf("Processo pai: %u\n", getpid());
        system("sleep 3");
        printf("Processo filho terminou: continuado ...\n");
    }
    // trecho de código-fonte em comum (ao pai e ao filho)
    printf("Programa finalizando: %u\n", getpid());
    return 0; // programa finaliza corretamente
}
