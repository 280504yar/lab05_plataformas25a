#ifndef ENLAZADA_H //header guards
#define ENLAZADA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
        //datos para el nodo
        int data;
        struct Node* next; //Cada nodo tiene una la direccion de memoria hacia el nodo siguiente (la flecha/el puntero)
} Nodo;

Nodo *Anadir_inic(Nodo *head, int n);

Nodo *Anadir_fin(Nodo *head, int n);

Nodo *Anadir_especif(Nodo *head, int pos, int data);

void Imprimir(Nodo *head);

Nodo *Eliminar_espec(Nodo *head, int data);

Nodo *Buscar(Nodo *head, int data);

void Eliminar_lista(Nodo *head);

#endif
