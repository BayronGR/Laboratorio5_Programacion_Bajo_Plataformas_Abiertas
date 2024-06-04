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

// Se inserta en una posición específica
void insert_into_a_position(DoubleList* list, int data, int position) {
    if (position == 0) {
        insert_at_start(list, data);
        return;
    }

    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->data = data;

    Nodo* actual = list->inicio;
    for (int i = 0; i < position - 1 && actual != NULL; i++) {
        actual = actual->siguiente;
    }

    if (actual == NULL || actual->siguiente == NULL) {
        insert_at_end(list, data);
    } else {
        nuevo_nodo->siguiente = actual->siguiente;
        nuevo_nodo->anterior = actual;
        actual->siguiente->anterior = nuevo_nodo;
        actual->siguiente = nuevo_nodo;
    }
}

// Se elimina un nodo
void delete_by_data(DoubleList* list, int data) {
    Nodo* actual = list->inicio;
    while (actual != NULL && actual->data != data) {
        actual = actual->siguiente;
    }
    if (actual == NULL) return;

    if (actual->anterior != NULL) {
        actual->anterior->siguiente = actual->siguiente;
    } else {
        list->inicio = actual->siguiente;
    }

    if (actual->siguiente != NULL) {
        actual->siguiente->anterior = actual->anterior;
    } else {
        list->final = actual->anterior;
    }

    free(actual);
}

