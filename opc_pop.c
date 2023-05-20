#include "monty.h"

/**
 * pop - Function that removes the opcode of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode being executed
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
	
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
