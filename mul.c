#include "monty.h"

void mul(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->n * (*stack)->next->n;

    (*stack)->next->n = result;

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
