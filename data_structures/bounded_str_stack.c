#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 5

typedef struct stack
{
    int maxsize;
    int top;
    char **items;
} stack;

stack *newStack(int capacity)
{
    stack *pt = (stack *)malloc(sizeof(stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (char **)malloc(sizeof(char *) * capacity);

    return pt;
}

// Utility function to return the size of the stack
int size(stack *pt)
{
    return pt->top + 1;
}

// Utility function to check whether the stack is empty
int isEmpty(stack *pt)
{
    return pt->top == -1; // or return size(pt) == 0;
}

// Utility function to check whether the stack is full
int isFull(stack *pt)
{
    return pt->top == pt->maxsize - 1; // or return size(pt) == pt->maxsize;
}

// Utility function to add an element to the stack
void push(stack *pt, char *s)
{
    // check if the stack is already full. If so, inserting an element
    // would lead to stack overflow
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting '%s'\n", s);

    // increment the top index and add an element
    pt->items[++pt->top] = s;
}

// Utility function to get top element in the stack
char *peek(stack *pt)
{
    // check for empty stack
    if (!isEmpty(pt))
        return pt->items[pt->top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to pop top element from the stack
char *pop(stack *pt)
{
    // check for stack underflow
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Removing '%s'\n", peek(pt));

    // return the top element from the stack, and decrement the stack
    // size by 1
    return pt->items[pt->top--];
}

// Utility function to display the entire stack
void display(stack *pt)
{
    int i;
    if (isEmpty(pt))
    {
        printf("The stack is empty\n");
        return;
    }

    printf("The current stack can be represented by:\n");
    for (i = pt->top; i >= 0; i--)
        printf("%s ", pt->items[i]);
    printf("\n");
}

int main()
{
    int capacity = MAX_CAPACITY;
    int choice;
    char *s, *element;
    stack *pt = newStack(capacity);
    char confirmation = 'Y';

    do
    {
        printf("Choose:\n1.push\n2.pop\n3.peek\n4.display\n5.size\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter a string: ");
            scanf("%s", s);
            printf("\n");
            push(pt, s);
            printf("\n'%s' was added to the top of the stack\n",
                   pt->items[pt->top]);
            break;

        case 2:
            element = pop(pt);
            printf("\n'%s' was removed from the stack\n", element);
            break;

        case 3:
            element = peek(pt);
            printf("\n'%s' is at the top of the stack\n", element);
            break;

        case 4:
            display(pt);
            break;

        case 5:
            printf("\nThe stack has a size of %d integers\n", size(pt));
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }

        printf("\nDo you want to continue? ");
        scanf(" %c", &confirmation);
        printf("\n");
    } while (confirmation == 'Y' || confirmation == 'y');

    return 0;
}
