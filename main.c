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