#include "monty.h"

void pstr(stack_t **stack)
{
    stack_t *temp = *stack;

    if (temp == NULL)
    {
        printf("\n");
        return;
    }

    while (temp)
    {
        if (temp->n <= 0 || temp->n > 127)
            break;

        printf("%c", temp->n);
        temp = temp->next;
    }

    printf("\n");
}
