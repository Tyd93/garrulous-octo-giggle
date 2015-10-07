/*
* Programa escrito en C por 
* Sebastian Urrutia que representa
* secuencialmente la funcion de hash
* para almacenar una base de datos 
* y mostrar su dispersion.
*/

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "libc\tablaHash.h"
#endif

#define TAMTABLA 1013

int main(int argc,char const *argv[]){
	tabla *t1 = creartabla(TAMTABLA);
	//cargar(t1);
	//buscar(t1,66346);
	return 0;
}