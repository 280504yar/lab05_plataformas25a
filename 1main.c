#include "stack.h"
#include <stdio.h>

void Menu() {
	printf("\nMenu de acciones dentro del Stack:\n");
	printf("1.Push (agregar elemento)\n");
	printf("2.Pop (sacar elemento)\n");
	printf("3.Peek (ver elemento superior)\n");
	printf("4.Verificar si el stack esta vacio o no\n");
	printf("5.Mostrar stack\n");
	printf("6.Salir\n");
}

int main () {
	Stack* stack = createStack();
	int opcion, valor;

	do {
		Menu();
		scanf("%d" , &opcion);

		switch(opcion) {
			case 1:
				printf("Ingrese valor que desea agregar: ");
				scanf("%d", &valor);
				push(stack, valor);
				break;
			case 2:
				printf("Elemento sacado: %d\n", pop(stack));
				break;
			case 3:
				printf("Elemento superior: %d\n", peek(stack));
				break;
			case 4:
				if(isEmpty(stack)) {
					printf("El stack esta vacio\n");
				}
				else {
					printf("El stack no esta vacio\n");
				}
				break;
			case 5:
				printStack(stack);
				break;
			case 6:
				printf("Saliendo...\n");
				break;
			default:
				printf("Opcion no valida\n");
		}
	} while(opcion !=6);

	destroyStack(stack);
	return 0;

}




