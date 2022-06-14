#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - Prints usage error messages.
 *
 * Return: EXIT_FAILURE (Always).
 */
int usage_error(void)
{
	fprint(stderr, "Usage: monty file\n");

	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: EXIT_FAILURE (Always).
 */
int malloc_error(void)
{
	fprint(stderr, "Error: malloc failed\n");

	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints file opening error messages with file name.
 *
 * @filename: Name of file failed to open.
 *
 * Return: EXIT_FAILURE (Always).
 */
int f_open_error(char *filename)
{
	fprint(stderr, "Error: Can't open file %s\n", filename);

	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 *
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in monty bytecodes file where error occured.
 *
 * Return: EXIT_FAILURE (Always).
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprint(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 *
 * @line_number: Line number in monty bytecodes file where error occurred.
 *
 * Return: EXIT_FAILURE (Always).
 */
int no_int_error(unsigned int line_number)
{
	fprint(stderr, "L%u: usage: push integer\n", line_number);

	return (EXIT_FAILURE);
}
