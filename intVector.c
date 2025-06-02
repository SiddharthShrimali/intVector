#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8
#define DOUBLING_THRESHOLD 0.9


typedef struct int_Vector {
    int size; //size of vector (no of elements)
    int maxCapacity; //max no of elements
    int *data; //pointer to the array
} intVector;

void initialise(intVector *p) {
    p->size = 0;
    p->maxCapacity = INITIAL_CAPACITY;
    p->data = calloc(INITIAL_CAPACITY, sizeof(int));
}

void push(intVector *p, int value) {
    p->size++;
    if (p->size >= (DOUBLING_THRESHOLD * p->maxCapacity)) {
        int *tempMemory = realloc(p->data, 2 * p->maxCapacity * sizeof(int));
        p->data = tempMemory;
        p->maxCapacity *= 2;
    }
    p->data[p->size - 1] = value;
}

int pop(intVector *p) {
    if (p->size == 0) {
        printf("Warning: Trying to pop from an empty vector! ");
        return -1;
    }
    else {
        p->size--;
    }
    if (p->size < (0.5 * p->maxCapacity) && (p->maxCapacity * 0.5) >= INITIAL_CAPACITY) {
        int *tempMemory = realloc (p->data, p->maxCapacity/2 * sizeof(int)); 
        p->data = tempMemory;
        p->maxCapacity /= 2;
    }
    return p->size;
}

void print(intVector *p) {
    if (p->size > 0) {
        printf("[%d,", p->data[0]);
    }
    else {
        printf("[]\n");
        return;
    }
    for(int i = 1; i < p->size-1; i++) {
        printf(" %d,", p->data[i]);
    }
    if (p->size > 0) {
        printf(" %d]\n", p->data[p->size-1]);
    }
}

void reverse(intVector *p) {
    int l = 0;
    int r = p->size-1;
    while(l < r) {
        int temp = p->data[l];
        p->data[l] = p->data[r];
        p->data[r] = temp;
        l++;
        r--;
    }
}

void destroy(intVector *p) {
    free(p->data);
    p->size = 0;
    p->maxCapacity = 0;
}

void empty(intVector *p) {
    destroy(p);
    initialise(p);
}
