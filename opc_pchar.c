#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
