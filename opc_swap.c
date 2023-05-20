#include "monty.h"

/**
 * swap - function that swaps the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode being executed
*/
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *top = *stack;
		stack_t *next = (*stack)->next;

		top->next = next->next;
		if (next->next != NULL)
			next->next->prev = top;

		next->prev = NULL;
		next->next = top;
		top->prev = next;

		*stack = next;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
}
