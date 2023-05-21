#include "monty.h"

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *top = *stack;
		stack_t *next = (*stack)->next;

		if (top->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", line_number);
			free_global_vars();
			exit(EXIT_FAILURE);
		}

		next->n /= top->n;
		pop(stack, line_number);
	}
	else
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
}
