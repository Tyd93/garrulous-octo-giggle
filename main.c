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

/*
* Modificar en la funcion buscar,
* el registro que se desea consultar
*/
int main(int argc,char const *argv[]){
	tabla *t1 = creartabla();
	cargar(t1);
	imprimirDispersion(t1);
	printf("Ingrese el registro que desea buscar: ");
	int registro = 0;
	scanf("%i",&registro);
	printf("\n");
	buscar(t1,registro);
	return 0;
}