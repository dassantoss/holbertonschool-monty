# include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		if (current->n == 0)
			break;

		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
