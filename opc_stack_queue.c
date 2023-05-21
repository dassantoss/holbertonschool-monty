#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_vars.lifo = 1;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_vars.lifo = 0;
}
