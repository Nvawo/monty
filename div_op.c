#include "monty.h"

void div_op(stack_t **stack, unsigned int line_number)
{
    int a, b;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    a = (*stack)->n;
    b = (*stack)->next->n;

    if (a == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n = b / a;
    pop(stack, line_number);
}
