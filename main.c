#include "enlazada_doble.h"

int main() {
	Nodo_d *head = NULL;

        printf("anadir al inicio \n");
        head = Anadir_inic_d(head, 1);
        printf("anadir al final \n");
        head = Anadir_fin_d(head, 2);
        head = Anadir_fin_d(head, 3);
        head = Anadir_fin_d(head, 4);
        head = Anadir_fin_d(head, 5);
        head = Anadir_fin_d(head, 6);
        printf("imprimir hacia adelante \n");
        Imprimir_d(head);

        printf("Al anadir especificamente en una posicion... \n");
        head = Anadir_especif_d(head, 4, 7);
        printf("imprimir hacia adelante \n");
        Imprimir_d(head);

        printf("Al borrar especificamente basado en la data... \n");
        head = Eliminar_espec_d(head, 3);
        printf("imprimir hacia adelante \n");
        Imprimir_d(head);

        printf("Al buscar... \n");
        Nodo_d *encontrado = Buscar_d(head, 9);
        printf("imprimir hacia adelante \n");
        Imprimir_d(encontrado);

        printf("Al imprimir todo hacia atras... \n");
        Imprimir_rev_d(head);
        return EXIT_SUCCESS;
}
