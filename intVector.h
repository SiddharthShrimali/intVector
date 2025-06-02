#ifndef intVector_h 
#define intVector_h
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8
#define DOUBLING_THRESHOLD 0.9

typedef struct int_Vector {
    int size; //size of vector (no of elements)
    int maxCapacity; //max no of elements
    int *data; //pointer to the array
} intVector;

void initialise(intVector *p);

void push(intVector *p, int value);

int pop(intVector *p);

void print(intVector *p);

void reverse(intVector *p);

void destroy(intVector *p);

void empty(intVector *p);

#endif

