/***
 Capitulo 2 listing 2.2 (getopt_long.c). Usando getopt_long
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
***/
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* El nombre de este programa. */
const char* program_name;
/* Imprime la informacion de uso de este programa en STREAM
(normalmente stdout o stderr), y sale el programa con EXIT_CODE. No vuelve*/

void print_usage(FILE* stream, int exit_code){
    fprintf(stream, "Usage: %s options[inputfile...]\n", program_name);
    fprintf(stream,
            "-h --help              Mostrar resumen de uso y salir.\n"
            "-o --output filename   Especificar nombre de archivo de salida.\n"
            "-v --verbose           Imprimir mensajes detallados.\n");
    exit(exit_code);        
}

/* Entrada al programa Main. ARGC contiene varios elementos de la lista de argumentos,
    ARGV es un array de punteros
*/

int main(int argc, char* argv[]){
    int next_option;
    /* Una cadena que enumera letras de opciones cortas validas*/
    const char* const short_options = "ho:v";
    /* Un array que describe opciones largas validas*/
    const struct option long_options[] ={
        {"help",    0,NULL,'h'},
        {"output",  1,NULL,'o'},
        {"verbose", 0,NULL,'v'},
        {NULL,      0,NULL, 0} /*Requerido al final del array*/
    };
    /* El nombre del archivo para recibir la salida del programa,
      o NULL para la salida estandar*/
      const char* output_filename = NULL;
      /* Si mostrar mensajes detallados */
      int verbose = 0;
      /*Recordar el nombre del programa, para incorporarlo en los mensajes.
      El nombre se almacena en argv[0]. */
      program_name = argv[0];
      do{
          next_option = getopt_long(argc, argv, short_options, long_options, NULL);

          switch(next_option){
              case 'h': /* -h or --help */
              /* El usuario ha solicitado informacion de uso. Imprimalo en la salida estandar
                 y salga con el codigo de salida uno (terminacion normal). */
                print_usage(stdout, 0);
             case 'o': /* -o or --output */
             /* Esta opcion toma un argumento, el nombre del archivo de salida */
                output_filename = optarg;
                break;
             case 'v': /* -v or --verbose */
                verbose = 1;
                break;
             case '?': /* El usuario ha especificado una opcion no valida */
             /* Imprima la informacion de uso con el error estandar y salga 
               con el codigo de salida uno (lo que indica una terminacion normal). */
                print_usage(stderr,1);
            case -1: /*Hecho con opciones */
                break;
            default: /* Algo mas: inesperado */
               abort();

          } //fin switch
      } while (next_option != -1);

      /* Hecho con opciones. OPTIND apunta al primer argumento 
      de no opcion. Para fines de demostracion, imprimalos si se
      especifico la opcion detallada */
      if(verbose){
          int i;
          for(i = optind; i < argc; ++i)
            printf("Argumento: %s\n", argv[i]);
      }
      /* El programa main va aqui*/
 return 0;
}