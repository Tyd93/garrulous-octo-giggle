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

#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#include <windows.h>
/*
* Modificar en la funcion buscar,
* el registro que se desea consultar
*/
int main(int argc,char const *argv[]){
	tabla *t1 = creartabla();
	time_t start,end; //Variables de tipo long int que almacenan un tiempo.
	time(&start);
	cargar(t1);
	time(&end);
	double tiempoTranscurrido = difftime(end,start);
	printf("El tiempo transcurrido para cargar fue : %f\n",tiempoTranscurrido);
	//Midiendo el tiempo para cargar
	imprimirDispersion(t1);
	printf("Ingrese el registro que desea buscar: ");
	int registro = 0;
	scanf("%i",&registro);
	printf("\n");
	time(&start);
	buscar(t1,registro);
	time(&end);
	tiempoTranscurrido = difftime(end,start);
	printf("El tiempo transcurrido en buscar fue: %f\n",tiempoTranscurrido );
	return 0;
}