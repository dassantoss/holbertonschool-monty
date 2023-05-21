#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void sub(stack_t **stack, unsigned int line_number)
{/*
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *top = *stack;
		stack_t *next = (*stack)->next;

		next->n -= top->n;
		pop(stack, line_number);
	}
	else
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}*/
		int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n -= (*stack)->n;
	pop(stack, line_number);
}
