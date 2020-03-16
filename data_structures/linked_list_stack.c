#include <stdio.h>
#include <stdlib.h>

// A linked list node
typedef struct Node
{
    char *data;        // string data
    struct Node *next; // pointer to the next node
} Node;

// Utility function to add a string s to the stack
void push(Node **top, char *s) // insert at the beginning
{
    // Allocate the new node at the heap
    Node *node = NULL;
    node = (Node *)malloc(sizeof(Node));

    // check if stack (heap) is full. If so, inserting an element would
    // lead to stack overflow
    if (!node)
    {
        printf("\nHeap Overflow");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %s\n", s);

    // set the data in allocated node
    node->data = s;

    // set the .next ponter of the new node to point to the current
    // top node of the list
    node->next = *top;

    // update top pointer
    *top = node;
}

// Utility function to test if the stack is empty or not
int isEmpty(Node *top)
{
    return top == NULL;
}

// Utility function to return top element in a stack
char *peek(Node *top)
{
    // check for empty stack
    if (!isEmpty(top))
        return top->data;
    else
        exit(EXIT_FAILURE);
}

// Utility function to pop top element from the stack
void pop(Node **top) // remove at the begginning
{
    Node *node;

    // check for stack underflow
    if (*top == NULL)
    {
        printf("\nStack Underflow");
        exit(EXIT_FAILURE);
    }

    printf("Removing %s\n", peek(*top));

    node = *top;

    // update the top pointer to point to the next node
    *top = (*top)->next;

    // free allocated memory for the previous top node
    free(node);
}

// Utility function to display all the elements in the stack
void display(Node *top)
{
    Node *node;

    if (isEmpty(top))
        printf("The stack is empty");
    else
    {
        node = top;
        printf("The current stack can be represented by:\n");
        while (node != NULL)
        {
            printf("'%s' ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    char *s, *element;
    Node *top = NULL;
    char confirmation = 'Y';

    do
    {
        printf("Choose:\n1.push\n2.pop\n3.peek\n4.display\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter a string: ");
            scanf("%s", s);
            printf("\n");
            push(&top, s);
            printf("\n'%s' was added to the top of the stack\n", s);
            break;

        case 2:
            element = peek(top);
            pop(&top);
            printf("\n'%s' was removed from the stack\n", element);
            break;

        case 3:
            element = peek(top);
            printf("\n'%s' is at the top of the stack\n", element);
            break;

        case 4:
            display(top);
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
