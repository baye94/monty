#ifndef __MONTY_H__
#define __MONTY_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct gvar_s - container for globally used variables
 * @file: The monty file being read
 * @lineNum: The current line number being read
 * @stack: The stack being used
 * @line: The current line being read
 */
typedef struct var_s
{
	FILE *file;
	unsigned int lineNum;
	stack_t *stack;
	char *line;
	char isStack;
} var_t;

extern var_t var;

void _printerr(char *c);
void openfile(char *name);
void fungetline(void);
void push(char *num);
void pall(stack_t **stack, unsigned int lineNum);
void runopcode(char *opcode, unsigned int lineNum);
void funfree(void);
void funopcodes(char *opcode, unsigned int lineNum);
void ValueDigit(char *num);
void Value_push(int elm);
void pint(stack_t **stack, unsigned int lineNum);

#endif /*  _MONTY_H_ */
