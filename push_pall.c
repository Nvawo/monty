#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - adds node to stack
 */
void push(stack_t **stack, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * pall - prints all stack values
 */
void pall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * handle_push - validates and pushes integer
 */
void handle_push(stack_t **stack, char *arg, unsigned int line_number)
{
	int i = 0, num;

	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (arg[0] == '-' || arg[0] == '+')
		i = 1;

	for (; arg[i]; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(arg);
	push(stack, num);
}

/**
 * pop - removes top element
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * pint - prints top element
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

/**
 * swap - swaps top two elements
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}

/**
 * add - adds top two elements
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n += first->n;

	*stack = second;
	second->prev = NULL;

	free(first);
}
/**
 * nop - does nothing
 * @stack: pointer to stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
