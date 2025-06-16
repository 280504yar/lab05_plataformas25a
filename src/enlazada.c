#include "enlazada.h"

//Creacion de nodo
Nodo *Anadir_inic(Nodo *head, int n) { //funcion que devuelve un puntero de tipo nodo, recibe la direccion de lista a la que le quiere agregar los nodos y los datos que se le quieren agregar
        Nodo* newnode = (Nodo *) malloc(sizeof(Nodo)); //Crear el nodo en la memoria dinamica
        if(newnode != NULL) { //Cuando no hay espacio malloc retorna NULL, si es distinto de NULL, se puede crear
                //acceder a los datos del struct y asignar el valor
                newnode->data = n;
                newnode->next = head; //el nuevo nodo, va a ser el primero (head)

                //introducir el nodo a la lista
                if(head == NULL) { //Si la lista esta recien creada, esta vacia
                        head = newnode; //head debe contener el primer nodo
                }
        } else {
                printf("No hay espacio \n");
        }

        return head;
}



Nodo *Anadir_fin(Nodo *head, int n) { //funcion que devuelve un puntero de tipo nodo, recibe la direccion de lista a la que le quiere agregar los nodos y los datos que se le quieren agregar
        Nodo* newnode = (Nodo *) malloc(sizeof(Nodo)); //Crear el nodo en un espacio de la memoria dinamica
        Nodo* tmp = NULL;
        if(newnode != NULL) { //Cuando no hay espacio malloc retorna NULL, si es distinto de NULL, se puede crear
                //acceder a los datos del struct y asignar el valor
                newnode->data = n;
                newnode->next = NULL; //el nuevo nodo, va a ser el ultimo, por lo tanto, va a apuntar a NULL

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

                }
        } else {
                printf("No hay espacio \n");
        }

        return head;
}



Nodo *Anadir_especif(Nodo *head, int pos, int data) { //funcion que devuelve un puntero de tipo nodo, recibe la direccion de lista a la que le quiere agregar los nodos y los datos que se le quieren agregar
        Nodo* newnode = (Nodo *) malloc(sizeof(Nodo)); //Crear el nodo en la memoria dinamica
        Nodo* tmp = head;
        int count = 0;
        if(newnode != NULL) { //Cuando no hay espacio malloc retorna NULL, si es distinto de NULL, se puede crear
                //acceder a los datos del struct y asignar el valor
                newnode->data = data;
                newnode->next = NULL; //el nuevo nodo, va a ser el ultimo, por lo tanto, va a apuntar a NULL

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
                        }
                        newnode->next = tmp->next;
                        tmp->next = newnode;



                }
        } else {
                printf("No hay espacio \n ");
	}

        return head;
}




void Imprimir(Nodo *head) { //se esta pasando el parametro de la lista por valor y no por referencia, no retorna, no hace falta auxiliares
        if (head != NULL) {
                while (head != NULL) {
                        printf("Data: %d Lista: %p y Lista->sig: %p\n",head->data,head,head->next);
                        head = head->next;
                }
        } else {
                printf("Lista vacia \n");
        }
}

//Eliminar en posicion especifica (busca el nodo, el que tenga el elemento es el que se va a borrar)
Nodo *Eliminar_espec(Nodo *head, int data) {
        Nodo *tmp = head;
        if(tmp->data == data) {  //si el primer nodo tiene el elemento que queremos borrar
                head = head->next;
                free(tmp); //Borrar el primer elemento
        } else { //Buscar en los demas nodos
                while (tmp->next != NULL) {
                        if(tmp->next->data == data) {
                                break;
                        }
                        tmp = tmp->next;
                }
                Nodo *eliminado = tmp->next;
                tmp->next = (tmp->next)->next; //cuando exista el espacio de memoria, acceder a su elemento y poder darle ese valor al que tiene en el siguiente
                free(eliminado);
        }
        return head;
}



Nodo *Buscar(Nodo *head, int data) {
        Nodo *tmp = head;
        if(tmp->data == data) { //si el nodo que buscamos resulta ser el primero
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

void Eliminar_lista(Nodo *head) {
        Nodo *tmp = NULL;
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
