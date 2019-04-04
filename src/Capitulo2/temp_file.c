/***
 Capitulo 2 listing 2.5 (client.c). Using mkstemp
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
***/
#include <stdlib.h>
#include <unistd.h>

/* Un identificador para un archivo temporal creado con write_temp_file.
    En esta implementacion, es solo un descriptor de archivo */
typedef int temp_file_handle;
/* Escribe bytes de longitud desde BUFFER en un archivo temporal. El 
 archivo temporal se desvincula inmediatamente. Devuelve un identificador
 al archivo temporal*/
 temp_file_handle write_temp_file (char* buffer, size_t length){
     /* Crea el nombre del archivo y el archivo. El XXXXXX sera reemplazado por caracteres
     que hacen que el nombre del archivo sea unico*/
     char temp_filename [] = "/tmp/temp_file.XXXXXX";
     int fd = mkstemp(temp_filename);
     /* Desvincula el archivo archivo inmediatamente, para que se elimine
     cuando se cierra el descriptor del archivo */
     unlink(temp_filename);
     /*Escribe primero el numero de bytes en el archivo */
     write(fd, &length, sizeof(length));
     /* Ahora escribe los datos en si */
     write(fd, buffer, length);
     /* Utilice el descriptor de archivo como el identificador del
      archivo temporal */
        return fd;
    }
 /* lee el contenido de un archivo temporal TEMP_FILE creado con write_temp_file
 El valor de entorno es un bufer recien asignado de esos contenidos, que la persona que llama debe
 designar. *LENGTH se establece en el tamanho del contenido, en bytes. El archivo temporal se elimina*/
  char* read_temp_file(temp_file_handle temp_file, size_t* length){
      char* buffer;
      /*El identificador de TEMP_FILE es un descriptor de archivo para el archivo temporal */
      int fd = temp_file;
      /* Rebobinar hasta el principio del archivo */
      lseek(fd, 0, SEEK_SET);
      /* Leer el tamnho de los datos en el archivo temporal */
      read(fd, length, sizeof(*length));
      /* Asignar un bufer y leer los datos */
      buffer = (char*)malloc(*length);
      /*Cierre del descriptor de archivo, lo que hara que el archivo temporal desaparezca*/
      close(fd);
      return buffer;
  }