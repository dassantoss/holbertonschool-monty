#include "monty.h"

/**
 * pint - Function that prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		dprintf("L%u: can't pint, stack empty\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
