#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* stack structure */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* mode system */
#define STACK_MODE 0
#define QUEUE_MODE 1

extern int mode;

/* core stack operations */
void push(stack_t **stack, int n);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack);
void rotl(stack_t **stack);
void rotr(stack_t **stack);

/* queue mode */
void queue_push(stack_t **stack, int n);
void set_stack_mode(void);
void set_queue_mode(void);

/* parser */
void execute_line(char *line, stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif
