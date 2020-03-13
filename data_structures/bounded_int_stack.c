#include <stdio.h>
#include <stdlib.h>

// Data structure for stack
struct stack
{
    int maxsize; // define max capacity of stack
    int top;
    int *items;
};

// Utility function to initialize stack
struct stack *newStack(int capacity)
{
    struct stack *pt = (struct stack *)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int *)malloc(sizeof(int) * capacity);

    return pt;
};

// Utility function to return the size of the stack
int size(struct stack *pt)
{
    return pt->top + 1;
}

// Utility function to check whether the stack is empty
int isEmpty(struct stack *pt)
{
    return pt->top == -1; // or return size(pt) == 0;
}

// Utility function to check whether the stack is full
int isFull(struct stack *pt)
{
    return pt->top == pt->maxsize - 1; // or return size(pt) == pt->maxsize;
}

// Utility function to add an element to the stack
void push(struct stack *pt, int x)
{
    // check if the stack is already full. If so, inserting an element
    // would lead to stack overflow
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %d\n", x);

    // increment the top index and add an element
    pt->items[++pt->top] = x;
}
