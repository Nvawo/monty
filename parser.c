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
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
