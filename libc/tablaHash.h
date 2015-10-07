/*
* Libreria asociada a la tabla hash:
*	- Funciones.
*	- Estructuras.
* Creado por Sebastian Urrutia
* 06-10-15
*/

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef NODO_H
#define NODO_H
#include "nodo.h"
#endif

#define RESTO 1013

/*
* Estructura que representara la tabla HASH
* El tamano lo determinara el usuario.
*/

typedef struct eTabla{
	int tamano;
	vertice *arreglo;
}tabla;


/*
* Funcion que inicializara cada elemento
* de la tabla como null.
*/

int inicializarTabla(tabla *t){
	for(int i = 0;i < t->tamano;i++){
		t->arreglo[i].lista = NULL;
		t->arreglo[i].largo = 0;
	}
	return 1;
}

/*
* Funcion hash.
* Puede ser cambiada segun la necesidad
* del desarrollador.
*/

int funcionHash(clave key){
	int indice = key % RESTO;
	return indice;
}

/*
* Funcion que imprime el nodo
* encontrado.
*/

int imprimir(nodo *encontrado){
	printf("Imprimiendo lo solicitado:\n");
	printf("\t- Nombre del local: %s\n",encontrado->fantasia);
	printf("\t- Direccion: %s\n",encontrado->direccion);
	printf("\t- Comuna: %s\n",encontrado->comuna);
	printf("\t- Entidad asociada: %s\n",encontrado->entidad);
	return 1;
}

/*
* Funcion que nos devolvera un puntero a 
* tabla con un tamaño que sea asignado por el 
* usuario.
* A "tam" en el main se le asignara el valor de
* la variable global "RESTO".
*/

tabla *creartabla(int tam){
	tabla *auxTabla = (tabla*)malloc(sizeof(tabla));
	auxTabla->tamano = tam;
	auxTabla->arreglo = (vertice *)malloc(tam *sizeof(vertice));
	inicializarTabla(auxTabla);
	return auxTabla;
}

/*
* Funcion que cargara los datos desde el
* archivo "puntos_bip.csv".
* la función sera llamada solo una vez.
*/

int cargar(tabla *t){
	char nombreArchivo[]= "puntos_bip.csv";
	FILE *archivo = fopen(nombreArchivo,"r");
	while(!feof(archivo)){
		nodo *auxNodo = (nodo *)malloc(sizeof(nodo));
		auxNodo->sig = NULL;
		printf("hola\n");
		fscanf(archivo,"%i;%s;%s;%s;%s",&(auxNodo->codigo),auxNodo->entidad,auxNodo->fantasia,auxNodo->direccion,auxNodo->comuna);
		int index = funcionHash(auxNodo->codigo);
		if(t->arreglo[index].largo == 0){
			t->arreglo[index].lista = auxNodo;
			t->arreglo[index].largo++;
		}
		else{
			auxNodo->sig = t->arreglo[index].lista;
			t->arreglo[index].lista = auxNodo;
			t->arreglo[index].largo++;
		}
	}
	return 1;
}

/*
* Funcion que busca el valor dado
* una clave en a tabla hash.
*/

int buscar(tabla *t, clave key){
	tabla *auxTabla = t;
	int index = funcionHash(key);
	int encontrado = 0;
	while(!encontrado){
		if(auxTabla->arreglo[index].lista->codigo == key){
			imprimir(auxTabla->arreglo[index].lista);
			encontrado = 1;
			return 1;
		}
		else if(auxTabla->arreglo[index].lista == NULL){
			return 0;
		}
		else{
			auxTabla->arreglo[index].lista = auxTabla->arreglo[index].lista->sig;
		}
	}
	return 0;
}