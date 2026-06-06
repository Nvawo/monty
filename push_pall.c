#include "monty.h"

/* push node */
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

/* push handler with validation */
void handle_push(stack_t **stack, char *arg, unsigned int line)
{
    int i = 0;
    int num;

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }

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

    num = atoi(arg);
    push(stack, num);
}
/**
 * pint - prints value at top of stack
 * @stack: pointer to stack
 * @line_number: line number (for error reporting)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
