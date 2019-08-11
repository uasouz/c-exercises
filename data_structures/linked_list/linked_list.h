//
// Created by Hadara on 2019-08-10.
//

#ifndef EXERCISES_LINKED_LIST_H
#define EXERCISES_LINKED_LIST_H
//Define ponteiro void generico
typedef void *genericType;

//Define struct do nó da lista
typedef struct LinkedList {
    genericType data;
    char *nodeType;
    struct LinkedList *next;
} LinkedList;

//Cria um alias node para o no da lista
typedef struct LinkedList *node;


#endif //EXERCISES_LINKED_LIST_H
