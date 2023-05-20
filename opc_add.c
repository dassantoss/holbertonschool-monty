#include "monty.h"

/**
 * add - function that adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode being executed
*/
void add(stack_t **stack, unsigned int line_number)
{
		if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *top = *stack;
		stack_t *next = (*stack)->next;

		next->n += top->n;
		pop(stack, line_number);
	}
	else
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
}
