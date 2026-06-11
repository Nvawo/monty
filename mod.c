#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n % (*stack)->n;

    (*stack)->next->n = result;

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
