#include "arraydinamico.h"
#include <stdlib.h>
#include <stdio.h>

//Crear arreglo dinámico
ArrayDinamico *crear(int capacidad_inicial) {
	if (capacidad_inicial <= 0) return NULL;

	ArrayDinamico *arr = malloc(sizeof(ArrayDinamico));
	if (!arr) return NULL;

	arr->datos = malloc(sizeof(int) * capacidad_inicial);
	if (!arr->datos) {
		free(arr);
		return NULL;
	}

	arr->capacidad = capacidad_inicial;
	arr->longitud = 0;
	return arr;
}

//Liberar arreglo dinámico
void liberar(ArrayDinamico *arr) {
	if (arr !=NULL) {
		free(arr->datos);
		free(arr);
	}
}

//Añadir elemento
int anadir(ArrayDinamico *arr, int valor) {
	if (arr->longitud >= arr->capacidad) {
		int nueva_capacidad = arr->capacidad * 2;
		int *nuevos_datos = realloc(arr->datos, sizeof(int) * nueva_capacidad);
		if (!nuevos_datos)
			return -1;
		arr->datos = nuevos_datos;
		arr->capacidad = nueva_capacidad;
	}

	arr->datos[arr->longitud] = valor;
	arr->longitud++;
	return 0;
}

//Eliminar elemento
int eliminar(ArrayDinamico *arr, int indice) {
	if (indice < 0 || indice >= arr->longitud)
		return -1;
	for (int i = indice; i < arr->longitud - 1; i++)
		arr->datos[i] = arr->datos[i+1];

	arr->longitud--;
	return 0;
}

//Obtener elemento
int obtener(const ArrayDinamico *arr, int indice, int *valor) {
	if (indice < 0 || indice >= arr->longitud) {
		printf("El índice ingresado no existe en el arreglo\n");
		return -1;
	}
	*valor = arr->datos[indice];
	return 0;
}

//Imprimir elemento
void imprimir(const ArrayDinamico *arr) {
	printf("[");
	for (int i = 0; i < arr->longitud; i++) {
		printf("%d", arr->datos[i]);
		if (i < arr->longitud - 1)
			printf(", ");
	}
	printf("]\n");
}



