#include "monty.h"

/**
 * get_opcodes - selects the opecode to perfom
 * 
 * @opcode: opcode sent
 * 
 * Return: Pointer to the function that executes the opcode
*/

void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{NULL,NULL}
	};

	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opcode) == 0)
			break;
	}

	return (instruct[i].f);	
}