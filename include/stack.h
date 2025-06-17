#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
	int valor;
	struct StackNode* next;
} StackNode;

typedef struct Stack{
	StackNode* top;
	int size;
} Stack;

Stack* createStack();             
void destroyStack(Stack* stack);
void push(Stack* stack, int valor);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
void printStack(Stack* stack);

#endif
