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
        push(stack, atoi(arg));
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
        div_op(stack, line_number);
    else if (strcmp(opcode, "mul") == 0)
        mul(stack, line_number);
    else if (strcmp(opcode, "sub") == 0)
        sub(stack, line_number);
    else if (strcmp(opcode, "mod") == 0)
        mod(stack, line_number);
    else if (strcmp(opcode, "pchar") == 0)
        pchar(stack, line_number);
    else if (strcmp(opcode, "pstr") == 0)
        pstr(stack);
    else if (strcmp(opcode, "rotl") == 0)
        rotl(stack);
else if (strcmp(opcode, "rotr") == 0)
    rotr(stack);
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n",
                line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
