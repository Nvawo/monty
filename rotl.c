#include "monty.h"

void rotl(stack_t **stack)
{
    stack_t *first;
    stack_t *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;
    last = *stack;

    while (last->next != NULL)
        last = last->next;

    *stack = first->next;
    (*stack)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;
}
