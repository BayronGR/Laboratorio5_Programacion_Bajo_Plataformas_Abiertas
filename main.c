#include <stdio.h>
#include "double_list.h"

//Se crea la lista
int main() {
    DoubleList* list = create_list();

//Se insertan nodos al inicio
    insert_at_start(list, 1);

//Se insertan nodos al final
    insert_at_end(list, 30);

//Se insertan nodos en posición específica
    insert_into_a_position(list, 15, 1);

// Se imprime la lista hacia delante
    printf("Lista hacia adelante: ");
    print_list_forward(list);

// Se imprime la lista hacia atrás
    printf("Lista hacia atrás: ");
    print_list_backward(list);

//Se elimina nodo
    delete_by_data(list, 15);
    printf("Después de eliminar 15, lista hacia adelante: ");
    print_list_forward(list);

// Se busca elemento a partir de su data
    Nodo* found = search_by_data(list, 10);
    if (found != NULL) {
        printf("Elemento 10 encontrado.\n");
    } else {
        printf("Elemento 10 no encontrado.\n");
    }

    free_list(list);
    return 0;
}