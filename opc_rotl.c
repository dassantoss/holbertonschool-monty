#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *last = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}
