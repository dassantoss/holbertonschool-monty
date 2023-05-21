#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: Doubly linked list node structure
 * for stack, queue, LIFO, FIFO.
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct globals - globals structure for to use in functions
 * @lifo: is stack or queue
 * @line: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @file_desc: files description
 * @buffer: input text
 * Description: Doubly linked list node structure
 * for stack, queue, LIFO, FIFO
*/
typedef struct globals
{
int lifo;
unsigned int line;
char *arg;
stack_t *head;
FILE *file_desc;
char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queue, LIFO, FIFO.
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t global_vars;

/*opcode_instructions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **satck, unsigned int	line_number);
void add(stack_t **satck, unsigned int	line_number);
void nop(stack_t **satck, unsigned int	line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

/*get opcode*/
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);

/*Imported functions*/
int _strcmp(char *s1, char *s2);
int char_in_string(char *str, char c);
char *_strtoky(char *str, char *delim);

/*doubly linked list functions*/
void free_doubly_linked_list(stack_t *head);
stack_t *add_node_at_end(stack_t **head, const int n);
stack_t *add_node_at_beginning(stack_t **head, const int n);

/*main*/
void free_global_vars(void);

/* ...otras declaraciones de funciones y estructuras... */
int is_comment(char *line);

#endif
