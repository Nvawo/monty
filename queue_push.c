#include "monty.h"

/**
 * queue_push - adds node at end of list
 * @stack: stack head
 * @n: value
 */
void queue_push(stack_t **stack, int n)
{
    stack_t *new_node;
    stack_t *temp;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        new_node->prev = NULL;
        *stack = new_node;
        return;
    }

    temp = *stack;

    while (temp->next)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}
