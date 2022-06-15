#include "monty.h"

var_t var;
/**
 * funopcodes - function that validates and compares the commands, by entering each function.
 * @opcode: The opcode to run
 * @lineNum: The line number the opcode
 *  * Return - Nothing, Function void
 */
void funopcodes(char *opcode, unsigned int lineNum)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; ++i)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&var.stack, lineNum);
			return;
		}
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lineNum, opcode);
	funfree();
	exit(EXIT_FAILURE);
}
