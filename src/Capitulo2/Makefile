###
 # FP-UNA
 # Lenguajes de Programacion 3 2019
 # Makefile Capitulo 2 
 #Integrantes:
 #@Miryam Godoy
 #@Alex Gomez
###
OBJECTS  	= 	readfile.o temp_file.o test.o
LIBRARIES 	= 	libtest.a libtest.so
PROGRAMS 	=	app arglist client getopt_long print-env tifftest

.PHONY: all clean

#Destino predeterminado: construir todo
all: $(PROGRAMS)

#Limpiar los productos de construccion
clean:
	   rm -f *.o *.a $(PROGRAMS)
#Dependencias adicionales
main:		reciprocal.o

libtest.a:	test.o
	ar cr $@ $?

libtest.so:	test.c
	$(CC) $(CFLAGS) -fPIC -shared $< -o $@

app:		LDLIBS += -L. -ltest
app:		app.c libtest.a

tifftest:	CFLAGS += -static
tifftest:	LDLIBS += -ltiff -ljpeg -lz -lm 
