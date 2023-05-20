#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void push(stack_t **doubly, unsigned int line_number)
{
	int n, j;

	if (!global_vars.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	for (j = 0; global_vars.arg[j] != '\0'; j++)
	{
		if (!isdigit(global_vars.arg[j]) && global_vars.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_global_vars();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global_vars.arg);

	if (global_vars.lifo == 1)
		add_node_at_beginning(doubly, n);
	else
		add_node_at_end(doubly, n);
}

/**
 * pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @line_number: line numbers
 * Return: no return
 */
void pall(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
