#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *top = *stack;
		stack_t *next = (*stack)->next;

		next->n *= top->n;
		pop(stack, line_number);  /* Remove the top element */
	}
	else
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
}
