#include "arraydinamico.h"
#include <stdio.h>

int main() {
//Crear el arreglo
	int tamano_inicial;
	printf("Ingrese el tamaño inicial del arreglo: ");
	scanf("%d", &tamano_inicial);
	ArrayDinamico *arr = crear(tamano_inicial);
	if (!arr) {
		printf("Error al crear el arreglo\n");
		return 1;
	}
	printf("El arreglo dinámico es: ");
	imprimir(arr);
	printf("\n");

//Añadir elemento del arreglo
	int elemento_a = 0;
	char opcion_a = 's';

	while (opcion_a == 's' || opcion_a == 'S') {
		printf("Añadir elemento al arreglo, escriba un número: ");
		scanf("%d", &elemento_a);
		anadir(arr, elemento_a);
		printf("El arreglo dinámico es: ");
		imprimir(arr);
		printf("¿Desea añadir otro elemento al arreglo? [S/N]: ");
		scanf(" %c", &opcion_a);
		printf("\n");
	}

//Eliminar elemento del arreglo
	int indice_e;
	char opcion_e = 's';
	while (opcion_e == 's' || opcion_e == 'S') {
		printf("Eliminar elemento al arreglo, escriba el índice: ");
		scanf("%d", &indice_e);
		eliminar(arr, indice_e);
		printf("El arreglo dinámico es: ");
		imprimir(arr);
		printf("¿Desea eliminar otro elemento al arreglo? [S/N]: ");
		scanf(" %c", &opcion_e);
		printf("\n");
	}

//Obtener elemento del arreglo
	int indice_o;
	int elemento_o = 0;
	char opcion_o = 's';
	while (opcion_o == 's' || opcion_o == 'S') {
		printf("Obtener elemento del arreglo, escriba el índice: ");
        	scanf("%d", &indice_o);
		if (obtener(arr, indice_o, &elemento_o) == 0)
			printf("Elemento en índice %d: %d\n", indice_o, elemento_o);
		printf("¿Desea obtener otro elemento al arreglo? [S/N]: ");
                scanf(" %c", &opcion_o);
                printf("\n");
        }

//Liberar arreglo dinámico
	printf("\n Final de funciones, liberando memoria\n");
	liberar(arr);
	return 0;
}

