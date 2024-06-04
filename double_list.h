#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Nodo {
    int data;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct DoubleList {
    Nodo* inicio;
    Nodo* final;
} DoubleList;

DoubleList* create_list();
void insert_at_start(DoubleList* list, int data);
void insert_at_end(DoubleList* list, int data);
void insert_into_a_position(DoubleList* list, int data, int position);
void delete_by_data(DoubleList* list, int data);
Nodo* search_by_data(DoubleList* list, int data);
void print_list_forward(DoubleList* list);
void print_list_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif      // DOUBLE_LIST_H