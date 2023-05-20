#include "monty.h"

global_t global_vars;

/**
 * free_global_vars - free the global variables
 * Return: no return
*/
void free_global_vars(void)
{
	free_doubly_linked_list(global_vars.head);
	free(global_vars.buffer);
	free(global_vars.file_desc);
}

/**
 * start_global_vars - Inicializes the global variables
 * @file_desc: file descriptor
 * Return: void
*/
void start_global_vars(FILE *file_desc)
{
	global_vars.lifo = 1;
	global_vars.line = 1;
	global_vars.arg = NULL;
	global_vars.head = NULL;
	global_vars.file_desc = file_desc;
	global_vars.buffer = NULL;
}

/**
 * check_input - Checks if the file exist and can be opened
 * @argc: Argument count
 * @argv: Argument vector
 * Return: file struct
*/
FILE *check_input(int argc, char *argv[])
{
	FILE *file_desc;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_desc = fopen(argv[1], "r");

	if (file_desc == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file_desc);
}

/**
 * main - ENtry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 success
*/
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file_desc;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	file_desc = check_input(argc, argv);
	start_global_vars(file_desc);
	nlines = getline(&global_vars.buffer, &size, file_desc);
	while (nlines != -1)
	{
		lines[0] = _strtoky(global_vars.buffer, " t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global_vars.line);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_global_vars();
				exit(EXIT_FAILURE);
			}
			global_vars.arg = _strtoky(NULL, " \t\n");
			f(&global_vars.head, global_vars.line);
		}
		nlines = getline(&global_vars.buffer, &size, file_desc);
		global_vars.line++;
	}

	free_global_vars();

	return (0);
}
