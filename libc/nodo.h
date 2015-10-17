/*
* Libreria tipo nodo, que representa
* una estructura tipo nodo la cual
* contiene una clave del tipo entera
* e informacion para representar un
* registro en una base de datos.
* Creado el 06-10-15 por 
* Sebastian Urrutia.
*/

/*
* El tipo de tabla de hash que se implementara
* sera el hash de encadenamiento.
* se aproximara las colisiones a 1.5.
*/


#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

/*
* La estructura de tipo nodo contendra las siguientes variables:
*		- Codigo del local.
*		- Entidad a cargo del sistema de recargas.
* 		- Nombre de fantasia del local.
*		- Nombre de la comuna en la que se ubica el local.
*/
typedef int clave;

typedef struct eNodo{
	clave codigo;
	char entidad[15];
	char fantasia[70];
	char direccion[70];
	char comuna[20];
	struct eNodo *sig;
}nodo;

/*
* Estructura que representara
* un vertice de la tabla HASH.
* contiene un tamaño de la lista anexada
* y un puntero al primer nodo.
*/

typedef struct eVertice{
	int largo;
	nodo *lista;
}vertice;