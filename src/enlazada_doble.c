#include "enlazada_doble.h"

//Creacion de nodo
Nodo_d *Anadir_inic_d(Nodo_d *head, int n) { //funcion que devuelve un puntero de tipo nodo, recibe la direccion de lista a la que le quiere agregar los nodos y los datos que se le quieren agregar
        Nodo_d* newnode = (Nodo_d *) malloc(sizeof(Nodo_d)); //Crear el nodo en la memoria dinamica
        if(newnode != NULL) { //Cuando no hay espacio malloc retorna NULL, si es distinto de NULL, se puede crear
                //acceder a los datos del struct y asignar el valor
                newnode->data = n;
                newnode->next = head; //el nuevo nodo, va a ser el primero (head)
		newnode->prev = NULL;
                //introducir el nodo a la lista
                if(head != NULL) { //Si la lista esta recien creada, esta vacia
                        head->prev = newnode; //head debe contener el primer nodo
                }
	} else {
                printf("No hay espacio \n");
        }

        return newnode;
}

Nodo_d *Anadir_fin_d(Nodo_d *head, int n) { //funcion que devuelve un puntero de tipo nodo, recibe la direccion de lista a la que le quiere agregar los nodos y los datos que se le quieren agregar
        Nodo_d* newnode = (Nodo_d *) malloc(sizeof(Nodo_d)); //Crear el nodo en la memoria dinamica
        Nodo_d* tmp = NULL;
        if(newnode != NULL) { //Cuando no hay espacio malloc retorna NULL, si es distinto de NULL, se puede crear
                //acceder a los datos del struct y asignar el valor
                newnode->data = n;
                newnode->next = NULL; //el nuevo nodo, va a ser el ultimo, por lo tanto, va a apuntar a NULL
		newnode->prev = NULL;
                //introducir el nodo a la lista
                if(head == NULL) { //Si la lista esta recien creada, esta vacia
                        head = newnode; //head debe contener el primer nodo
                } else { //si ya no esta vacia
                        //Agregar nodo  de ultimo, recorrer la lista,  hasta que llegue a NULL, para llegar a la posicion antes de NULL
                        //Necesario usar auxiliares para evitar la eliminacion de la lista (nodos anteriores al ultimo)
                        tmp = head; //tmp inicia siendo igual al primer nodo
                        while (tmp->next != NULL) { //recorrera hasta el nodo antes de NULL
                                tmp = tmp->next;
                        }
                        tmp->next = newnode;
			newnode->prev = tmp;

                }
	} else {
                printf("No hay espacio \n");
        }

        return head;
}

Nodo_d *Anadir_especif_d(Nodo_d *head, int pos, int data) { //funcion que devuelve un puntero de tipo nodo, recibe la direccion de lista a la que le quiere agregar los nodos y los datos que se le quieren agregar
        Nodo_d* newnode = (Nodo_d *) malloc(sizeof(Nodo_d)); //Crear el nodo en la memoria dinamica
        Nodo_d* tmp = head;
        int count = 0;
        if(newnode != NULL) { //Cuando no hay espacio malloc retorna NULL, si es distinto de NULL, se puede crear
                //acceder a los datos del struct y asignar el valor
                newnode->data = data;
                newnode->next = NULL; //el nuevo nodo, va a ser el ultimo, por lo tanto, va a apuntar a NULL
		newnode->prev = NULL;
                //introducir el nodo a la lista
                if(head == NULL) { //Si la lista esta recien creada, esta vacia
                        head = newnode; //head debe contener el primer nodo
                } else { //si ya no esta vacia
                        //Agregar nodo  de ultimo, recorrer la lista,  hasta que llegue a NULL, para llegar a la posicion antes de NULL
                        //Necesario usar auxiliares para evitar la eliminacion de la lista (nodos anteriores al ultimo)
                        tmp = head; //tmp inicia siendo igual al primer nodo
                        while (tmp->next != NULL && count < pos - 1) { //recorrera hasta el nodo antes de NULL
                                tmp = tmp->next;
                                ++count;

                        }
                        if (tmp->next == NULL) {
                                free(newnode);
                                printf("posicion invalida \n");
                                return NULL;
                        }
                        newnode->next = tmp->next;
			if(newnode->next != NULL) {
				newnode->next->prev = newnode;
			}
			newnode->prev = tmp;
                        tmp->next = newnode;
		}
	} else {
                printf("No hay espacio \n ");
        }

        return head;
}


void Imprimir_d(Nodo_d *head) { //se esta pasando el parametro de la lista por valor y no por referencia (osea asi: **Lista), no retorna, no hace falta auxiliares
        if (head != NULL) {
                while (head != NULL) { //si fuera Lista->sig no se tomaria en cuenta al ultimo
                        printf("Data: %d Lista: %p y Lista->sig: %p\n",head->data,head,head->next);
                        head = head->next;
                }
        } else {
                printf("Lista vacia \n");
        }
}

//Cada vez que quiero modificar algo en la lista, la funcion debe retonar un elemento del tipo de esa lista y hay que usar un auxiliar

//Eliminar en posicion especifica (busca el nodo, el que tenga el elemento es el que se va a borrar)
Nodo_d *Eliminar_espec_d(Nodo_d *head, int data) {
        Nodo_d *tmp = head;
        if(tmp->data == data) {  //si el primer nodo tiene el elemento que queremos borrar
                head = head->next;
		if(head != NULL) {
			head->prev = NULL;
		}
                free(tmp); //Borrar el primer elemento
        } else { //Buscar en los demas nodos
        
                while (tmp->next != NULL) {
                        if(tmp->next->data == data) {
                                break;
                        }
                        tmp = tmp->next;
                }
                Nodo_d *eliminado = tmp->next;
                tmp->next = (tmp->next)->next; //cuando exista el espacio de memoria, acceder a su elemento y poder darle ese valor al que tiene en el siguiente
                if(tmp->next != NULL) {
			tmp->next->prev = tmp;
		}
		free(eliminado);
        }
        return head;
}

Nodo_d *Buscar_d(Nodo_d *head, int data) {
        Nodo_d *tmp = head;
        if(tmp->data == data) {  //si el primer nodo tiene el elemento que queremos borrar
                return head;
               
        } else { //Buscar en los demas nodos
        
                while (tmp->next != NULL) {
                        if(tmp->next->data == data) {
                                break;
                        }
                        tmp = tmp->next;
                }
        }
        return tmp->next;
}

void Imprimir_rev_d(Nodo_d *head) { //se esta pasando el parametro de la lista por valor y no por referencia (osea asi: **Lista), no retorna, no hace falta auxiliares
        if (head == NULL) {
		printf("lista vacia \n");
		return;
	}
	Nodo_d *tmp = head;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}

	while(tmp != NULL) {
		printf("Data: %d Lista: %p y lista->prev: %p \n", tmp->data, tmp, tmp->prev);
                tmp = tmp->prev;
	}
}
         

void Eliminar_lista_d(Nodo_d *head) { //se esta pasando el parametro de la lista por valor y no por referencia (osea asi: **Lista), no retorna, no hace falta auxiliares
        Nodo_d *tmp = NULL;
        if (head != NULL) {
                while (head != NULL) { //si fuera Lista->sig no se tomaria en cuenta al ultimo
                        tmp = head; //guardar lista
                        head = head->next;
                        free(tmp); //borrar lista
                }
        } else {
                printf("Lista vacia \n");
        }
}
