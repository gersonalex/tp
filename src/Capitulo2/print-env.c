/***
 Capitulo 2 listing 2.3 (print-env.c). Printing the Execution Environment
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
***/
#include <stdio.h>
/* La variable ENVIRON contiene el entorno*/
extern char** environ;
int main(){
    char ** var;
    for(var = environ; *var != NULL; ++var)
        printf("%s\n", *var);
 return 0;
}