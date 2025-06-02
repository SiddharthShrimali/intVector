#ifndef intVector_ll_h
#define intVector_ll_h
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next; 
} node;

typedef struct List {
    int size; //number of nodes
    node *firstNode; //first node
    node *lastNode; //last node
} list;

void initialise(list *head);

void print(list *head);

void push(list *head, int value);

int call(list *head, int index);

void change(list *head, int index, int value);

void pop(list *head);

void empty(list *head);

void destroy(list *head);

void reverseSlow(list *head);

void reverse(list *head);

#endif