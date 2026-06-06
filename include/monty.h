#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* stack node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* instruction mapping */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* functions */
void push(stack_t **stack, int n);
void pall(stack_t **stack);

/* opcode handlers */
void handle_push(stack_t **stack, char *arg, unsigned int line);
void execute_line(char *line, stack_t **stack, unsigned int line_number);

#endif
