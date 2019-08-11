//
// Created by Hadara on 2019-08-10.
//

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

#define get_type_initials(x) _Generic((x), \
    char: "c", \
    signed char: "hhd", \
    unsigned char: "hhu", \
    signed short: "hd", \
    unsigned short: "hu", \
    signed int: "d", \
    unsigned int: "u", \
    long int: "ld", \
    unsigned long int: "lu", \
    long long int: "lld", \
    unsigned long long int: "llu", \
    float: "f", \
    double: "lf", \
    long double: "Lf", \
    char *: "s", \
    void *: "p")

//#define printf_dec_format(x) _Generic((x), \
//    char: "%c", \
//    signed char: "%hhd", \
//    unsigned char: "%hhu", \
//    signed short: "%hd", \
//    unsigned short: "%hu", \
//    signed int: "%d", \
//    unsigned int: "%u", \
//    long int: "%ld", \
//    unsigned long int: "%lu", \
//    long long int: "%lld", \
//    unsigned long long int: "%llu", \
//    float: "%f", \
//    double: "%f", \
//    long double: "%Lf", \
//    char *: "%s", \
//    void *: "%p")
//
//#define print(x) printf(printf_dec_format(x), x)
//#define printnl(x) printf(printf_dec_format(x), x), printf("\n");

node criarNo(genericType input, char *nodeType) {
    node newNode;
    newNode = (node) malloc(sizeof(struct LinkedList));
    newNode->data = input;
    newNode->nodeType = nodeType;
    newNode->next = NULL;
    return newNode;
}

node buscaFinalLista(node item) {
    if (item->next != NULL) {
        return buscaFinalLista(item->next);
    }
    return item;
}

void imprimeLista(node item) {
    char* printFormat = malloc(sizeof(item->nodeType+1));
    sprintf(printFormat,"%c%s",'%',item->nodeType);
    printf(printFormat, item->data), printf("->");
    if (item->next != NULL) {
        imprimeLista(item->next);
    }
}

node insereValor(node inicio, genericType input, char *nodeType) {
    if (inicio == NULL) {
        inicio = criarNo(input, nodeType);
    } else {
        node final = buscaFinalLista(inicio);
        final->next = criarNo(input, nodeType);
    }
    return inicio;
}

int main() {
    node inicio = criarNo("Head", get_type_initials("Head"));
    for(int i = 0;i<1000;i++) {
        insereValor(inicio, i, get_type_initials(i));
    }

    imprimeLista(inicio);
}