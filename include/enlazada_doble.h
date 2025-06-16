#ifndef ENLAZADA_DOBLE_H //header guards
#define ENLAZADA_DOBLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_d {
        //datos para el nodo
        int data;
        struct Node_d* next; //Cada nodo tiene una la direccion de memoria hacia el nodo siguiente (la flecha/el puntero)
        struct Node_d* prev;
} Nodo_d;

Nodo_d *Anadir_inic_d(Nodo_d *head, int n);

Nodo_d *Anadir_fin_d(Nodo_d *head, int n);

Nodo_d *Anadir_especif_d(Nodo_d *head, int pos, int data);

void Imprimir_d(Nodo_d *head);

Nodo_d *Eliminar_espec_d(Nodo_d *head, int data);

Nodo_d *Buscar_d(Nodo_d *head, int data);

void Imprimir_rev_d(Nodo_d *head);

void Eliminar_lista_d(Nodo_d *head);

#endif
