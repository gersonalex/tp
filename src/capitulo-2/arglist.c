/***
 Capitulo 2 listing 2.1 (argclist.c). Usando argc y argv
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
***/
#include <stdio.h>
int main(int argc, char * argv[]){
    printf("El nombre de este programa es '%s'.\n", argv[0]);
    printf("Este programa fue invocado con %d argumentos.\n", argc-1);

    /* Se especificaron arguementos de la linea de comando?*/
    if(argc > 1){
        /* Si, imprimelos */
        int i;
        printf("Los arguementos son: \n");
        for(i=1; i<argc; i++)
        printf("%s\n", argv[i]);
    }
    return 0;
}