#include "monty.h"

/* push node at top */
void push(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/* print stack */
void pall(stack_t **stack)
{
    stack_t *temp = *stack;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
void handle_push(stack_t **stack, char *arg, unsigned int line)
{
    int n;
    int i = 0;

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }

    /* validate number */
    if (arg[0] == '-' || arg[0] == '+')
        i = 1;

    for (; arg[i]; i++)
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            fprintf(stderr, "L%d: usage: push integer\n", line);
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(arg);
    push(stack, n);
}
