#ifndef ARRAYDINAMICO_H
#define ARRAYDINAMICO_H


typedef struct {
	int *datos;
	int capacidad;
	int longitud;
} ArrayDinamico;

ArrayDinamico *crear(int capacidad_inicial);
void liberar(ArrayDinamico *arr);
int anadir(ArrayDinamico *arr, int valor);
int eliminar(ArrayDinamico *arr, int indice);
int obtener(const ArrayDinamico *arr, int indice, int *valor);
void imprimir(const ArrayDinamico *arr);

#endif
