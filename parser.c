#include "monty.h"

void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode;
    char *arg;

    opcode = strtok(line, " \t\n");

    if (!opcode || opcode[0] == '#')
        return;

    arg = strtok(NULL, " \t\n");

    if (strcmp(opcode, "push") == 0)
        handle_push(stack, arg, line_number);
    else if (strcmp(opcode, "pall") == 0)
        pall(stack);
else if (strcmp(opcode, "pint") == 0)
	pint(stack, line_number);
else if (strcmp(opcode, "pop") == 0)
	pop(stack, line_number);
else if (strcmp(opcode, "swap") == 0)
	swap(stack, line_number);
else if (strcmp(opcode, "add") == 0)
	add(stack, line_number);
else if (strcmp(opcode, "nop") == 0)
	nop(stack, line_number);
else if (strcmp(opcode, "div") == 0)
	_div(stack, line_number);
 else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
