/***
 Capitulo 2 listing 2.4 (client.c). Part of a Network Client Program
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
***/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* server_name = getenv("SERVER_NAME");
    if(server_name == NULL)
        /* La variable de entorno SERVER_NAME no se configuro.
            Utilice el valor predeterminado */
         server_name = "server.my-company.com";
    printf("accediendo a servidor %s\n", server_name);
 /* Acceso del servidor aqui...*/
 return 0;
}