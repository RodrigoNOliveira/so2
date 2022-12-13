#include <sys/types.h>
#include <stdio.h>
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
        usleep( 1000 );
        printf("Processo filho vai finalizar sua atividade: %u \n", getpid() );
    } else {
        // processo pai sendo executado !
        printf("Processo pai: %u\n", getpid());
        usleep( 30000 );
        printf("Processo filho terminou: continuado ...\n");
    }
    // trecho de código-fonte em comum (ao pai e ao filho)
    printf("Programa finalizando: %u\n", getpid());
    return 0; // programa finaliza corretamente
}
