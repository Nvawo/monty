#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 */
void rotr(stack_t **stack)
{
    stack_t *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}
