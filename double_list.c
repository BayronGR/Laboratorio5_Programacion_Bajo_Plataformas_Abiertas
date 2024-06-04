#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Se crea la lista doble
DoubleList* create_list() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->inicio = NULL;
    list->final = NULL;
    return list;
}

// Se inserta nodo al inicio
void insert_at_start(DoubleList* list, int data) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->data = data;
    nuevo_nodo->siguiente = list->inicio;
    nuevo_nodo->anterior = NULL;
    if (list->inicio != NULL) {
        list->inicio->anterior = nuevo_nodo;
    } else {
        list->final = nuevo_nodo;
    }
    list->inicio = nuevo_nodo;
}

// Se inserta nodo al final
void insert_at_end(DoubleList* list, int data) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->data = data;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = list->final;
    if (list->final != NULL) {
        list->final->siguiente = nuevo_nodo;
    } else {
        list->inicio = nuevo_nodo;
    }
    list->final = nuevo_nodo;
}