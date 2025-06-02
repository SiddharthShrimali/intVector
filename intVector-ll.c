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

void initialise(list *head) {
    head->size=0;
    head->firstNode=NULL;
    head->lastNode=NULL;
}

void print(list *head) {
    node *current = head->firstNode;
    while(current != head->lastNode) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    if (current != NULL) {
        printf("%d\n", current->data);
    }
}

void push(list *head, int value) {
    if(head->size == 0) {
        head->lastNode = (node*) malloc(sizeof(node));
        head->firstNode=head->lastNode;
    }
    else {
        head->lastNode->next = (node*) malloc(sizeof(node));
        head->lastNode = head->lastNode->next;
    }
    head->lastNode->data = value;
    head->lastNode->next = NULL;
    head->size++;
}

int call(list *head, int index) {
    if (index > head->size-1) {
        printf("Error: Trying to access %d index! Structure only has %d elements.", index, head->size);
        exit(1);
    }
    else {
        node *current;
        current = head->firstNode;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
}

void change(list *head, int index, int value) {
    if (index > head->size-1) {
        printf("Error: Trying to access %d index! Structure only has %d elements.", index, head->size);
    }
    else {
        node *current;
        current = head->firstNode;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = value;
    }
}

void pop(list *head) {
    if (head->size == 0) {
        printf("Warning: Trying to pop from an empty list!\n");
        return;
    }
    else if (head->size == 1) {
        free(head->firstNode);
        initialise(head);
        return; 
    }
    head->size--;
    node *current = head->firstNode;
    while(current->next != head->lastNode) {
        current = current->next;
    }
    free(head->lastNode);
    head->lastNode = current;
    current->next = NULL;
}

void empty(list *head) {
    node *current = head->firstNode;
    for (int i = head->size; i >0; i--) {
        head->firstNode = head->firstNode->next;
        free(current);
        current = head->firstNode;
        head->size--;
    }
    head->lastNode = NULL;
}

void destroy(list *head) {
    empty(head);
}

void reverseSlow(list *head) {
    if (head->size == 0 || head->size == 1) {
        return;
    }
    node *current = head->firstNode;
    int k = head->size-2;
    while (current->next != head->lastNode) {
        current = current->next;
    }
    head->lastNode->next = current;
    for (int i = 0; i < head->size-2; i++) {
        node *currentR = current;
        current = head->firstNode;
        for (int j = k; j > 1; j--) {
            current = current->next;
        }
        currentR->next = current;   
        k--; 
    }
    head->firstNode->next = NULL;
    node *temp;
    temp = head->firstNode;
    head->firstNode = head->lastNode;
    head->lastNode = temp;
}

void reverse(list *head) {
    if (head->size == 0 || head->size == 1) {
        return;
    }
    node *x = head->firstNode;
    node *y = x->next;
    node *z = y->next;
    for(int i = 0; i < head->size-2; i++) {
        y->next = x;
        x = y;
        y = z;
        z = z->next;
    }
    y->next = x;
    head->firstNode->next = NULL;
    z = head->firstNode;
    head->firstNode = head->lastNode;
    head->lastNode = z;
}