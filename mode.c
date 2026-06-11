#include "monty.h"

int mode = STACK_MODE;

/**
 * set_stack_mode - switch to stack mode
 */
void set_stack_mode(void)
{
    mode = STACK_MODE;
}

/**
 * set_queue_mode - switch to queue mode
 */
void set_queue_mode(void)
{
    mode = QUEUE_MODE;
}
