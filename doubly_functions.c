#include "monty.h"

/**
 * free_doubly_linked_list - Frees a doubly linked list.
 * @head: Pointer to the head to the list
 * Description: This function frees the memory allocated
 * for a doubly linked list.
 * Its starts from the head of the list and iteratively
 * frees each node.
 * Return: void
*/
void free_doubly_linked_list(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * add_node_at_beginning - Adds a node at the beginning of a doubly linked list
 * @head: Pointer to the first position of the linked list
 * @n: Data to store in the new node
 *
 * Return: Pointer to the updated doubly linked list
 */
stack_t *add_node_at_beginning(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	(*head)->prev = new_node;
	new_node->next = (*head);
	new_node->prev = NULL;
	*head = new_node;

	return (*head);
}

/**
 * add_node_at_end - Adds a node at the end of a doubly linked list
 * @head: Pointer to the first position of the linked list
 * @n: Data to store in the new node
 *
 * Return: Pointer to the updated doubly linked list
 */
stack_t *add_node_at_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;

	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next = new_node;

	return (new_node);
}
