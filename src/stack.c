#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack() {
	Stack* nuevo_stack = (Stack*)malloc(sizeof(Stack));
	if (nuevo_stack == NULL) {         //por si stack falla
		printf("No se pudo crear el stack\n");
		return NULL;
	}
	nuevo_stack->top = NULL;
	nuevo_stack->size = 0;
	return nuevo_stack;
}

void destroyStack(Stack* stack) {
	if (stack == NULL) {
		printf("El stack no existe\n");   //en caso de que no ha nada que borrar	
		return;
	}
	while(stack->top != NULL) {
		pop(stack);
	}
	free(stack);
}

void push(Stack* stack, int valor) {
	StackNode* nuevo_nodo = (StackNode*)malloc(sizeof(StackNode));
	if (nuevo_nodo == NULL) {
		printf("Imposible crear el nodo\n");
		return;
	}

	nuevo_nodo->valor = valor;
	nuevo_nodo->next = stack->top;
	stack->top = nuevo_nodo;
	stack->size++;
}

int pop(Stack* stack) {
	if (isEmpty(stack)) {
		return -1;
	}
	StackNode* nodo_eliminado = stack->top;
	int valor = nodo_eliminado->valor;
	stack->top = nodo_eliminado->next;
	free(nodo_eliminado);                     //liberamos memoria
	stack->size--;
	return valor;
}

int peek(Stack* stack) {
	if (isEmpty(stack)) {
		printf("El stack no contiene nada\n");
		return -1;
	}
	return stack->top->valor;
}

int isEmpty(Stack* stack) {
	if(stack == NULL) {
		return 1;
	}
	return stack->top == NULL;
}

void printStack(Stack* stack) {
	if(isEmpty(stack)) {
		printf("El stack no contiene nada\n");
		return;
	}
	printf("Stack de arriba para abajo\n");
	StackNode* actual = stack->top;
	while (actual != NULL) {
		printf("%d ", actual->valor);
		actual = actual->next;
	}
	printf("\n");
}
