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
	vertice arreglo[RESTO];
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
* Anadida el 17-10-15.
* Basicamente quita el "_" del
* campo y lo reemplaza por un
* " ".
*/

int quitaGuionBajo(nodo *encontrado){
	int indiceString = 0;
	while(encontrado->entidad[indiceString] != '\0'){
		if(encontrado->entidad[indiceString] == '_'){
			encontrado->entidad[indiceString] = ' ';
		}
		indiceString++;
	}
	indiceString = 0;
	while(encontrado->fantasia[indiceString] != '\0'){
		if(encontrado->fantasia[indiceString] == '_'){
			encontrado->fantasia[indiceString] = ' ';
		}
		indiceString++;
	}
	indiceString = 0;
	while(encontrado->direccion[indiceString] != '\0'){
		if(encontrado->direccion[indiceString] == '_'){
			encontrado->direccion[indiceString] = ' ';
		}
		indiceString++;
	}
	indiceString = 0;
	while(encontrado->comuna[indiceString] != '\0'){
		if(encontrado->comuna[indiceString] == '_'){
			encontrado->comuna[indiceString] = ' ';
		}
		indiceString++;
	}
	return 1;
}

/*
* Funcion que imprime el nodo
* encontrado.
* Imprime cada campo del registro.
*/

int imprimir(nodo *encontrado){
	quitaGuionBajo(encontrado);
	printf("Imprimiendo lo solicitado:\n");
	printf("\tEntidad a cargo: %s\n",encontrado->entidad);
	printf("\tNombre: %s\n",encontrado->fantasia);
	printf("\tDireccion: %s\n",encontrado->direccion);
	printf("\tComuna: %s\n",encontrado->comuna);
	return 1;
}

/*
* Funcion que nos devolvera un puntero a 
* tabla con un tamaño que sea asignado por el 
* usuario.
* A "tam" en el main se le asignara el valor de
* la variable global "RESTO".
*/

tabla *creartabla(){
	tabla *auxTabla = (tabla*)malloc(sizeof(tabla));
	auxTabla->tamano = RESTO;
	inicializarTabla(auxTabla);
	return auxTabla;
}

/*
* Funcion que cargara los datos desde el
* los archivos que se encuentren en el directorio.
* la función sera llamada solo una vez.
*/

int cargar(tabla *t){
	FILE *archivo = fopen("libc/puntos_bip.txt","r");
	if(archivo != NULL){
		while(!feof(archivo)){
			nodo *auxNodo = (nodo *)malloc(sizeof(nodo));
			auxNodo->sig = NULL;
			fscanf(archivo,"%i %s %s %s %s\n",&(auxNodo->codigo),auxNodo->entidad, auxNodo->fantasia, auxNodo->direccion, auxNodo->comuna);
			//printf("%s\n",auxNodo->fantasia);
			//getchar();
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
		fclose(archivo);
		return 1;
	}
	printf("Archivo no encontrado\n");
	return 0;
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
		if(auxTabla->arreglo[index].largo >= 1){
			if(auxTabla->arreglo[index].lista == NULL){
				printf("No existe\n");
				return 0;
			}
			if(auxTabla->arreglo[index].lista->codigo == key){
				imprimir(auxTabla->arreglo[index].lista);
				encontrado = 1;
				return 1;
			}
			else{
				auxTabla->arreglo[index].lista = auxTabla->arreglo[index].lista->sig;
			}			
			
		}
		else{
			printf("No se hayan datos\n");
			return 0;
		}
	}
	return 0;
}

/*
* Funcion que me imprimira la dispersion
* del hash en cadena implementado por
* mi funcion de Hash.
*/

int imprimirDispersion(tabla *t){
	tabla *auxTabla = t;
	FILE *archivoCsv = fopen("dispersion_bip.csv","w");
	for(int i = 0; i<RESTO;i++){
		fprintf(archivoCsv, "%i;%i\n",i,auxTabla->arreglo[i].largo);
	}
	fclose(archivoCsv);
	return 1;
}

/*
* Imprimir grafico dispersion.
* Imprime un grafico visual en consola
* del numero de elementos que contiene cada
* nodo
*/

int imprimirDispersionGrafica(tabla *t){
	tabla *auxTabla = t;
	int indiceTabla = 0;
	FILE *archivoTxt = fopen("dispersion_bip.txt","w");
	while(indiceTabla < RESTO){
		fprintf(archivoTxt,"[%i] ",indiceTabla);
		for(int x = 0;x < auxTabla->arreglo[indiceTabla].largo;x++){
			fprintf(archivoTxt,"=");
		}
		fprintf(archivoTxt,"\n");
		indiceTabla++;
	}
	fclose(archivoTxt);
	return 1;
}