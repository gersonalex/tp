/***
 Capitulo 2 listing 2.6 (readfile.c). Freeing Resources During Abnormal Conditions
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
***/
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char* read_from_file (const char* filename, size_t length)
{
  char* buffer;
  int fd;
  ssize_t bytes_read;

  /* Asignar buffer.  */
  buffer = (char*) malloc (length);
  if (buffer == NULL)
    return NULL;
  /* Abrir el archivo.  */
  fd = open (filename, O_RDONLY);
  if (fd == -1) {
    /* Error de apertura. Desasignar el buffer antes de volver.  */
    free (buffer);
    return NULL;
  }
  /* Leer los datos.  */
  bytes_read = read (fd, buffer, length);
  if (bytes_read != length) {
    /* Lectura fallida.  Desasignar el buffer y cerrar fd antes de volver.  */
    free (buffer);
    close (fd);
    return NULL;
  }
  /* Todo esta bien.  Cerrar el archivo y devolver el buffer.  */
  close (fd);
  return buffer;
}