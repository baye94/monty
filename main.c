#include "monty.h"

var_t var;

/**
 * main - Main function the program enters in
 * @argc: The number of arguments passed to the program
 * @argv: Double pointer of an arry
 * Return - 0 success or 1
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	var.stack = NULL;
	var.line = NULL;
	var.isStack = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	fungetline();
	funfree();
	return (0);
}

/**
 * openfile - Open the file.
 * @name: The name of the file
 * Return - Nothing, Function void
 */
void openfile(char *name)
{
	FILE *file;

	file = fopen(name, "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	var.file = file;
}

/**
 * fungetline - function that reads, line by line.
 * Return - Nothing, Function void
 */
void fungetline(void)
{
	ssize_t read;
	size_t len = 0;
	char *opcode;

	while ((read = getline(&var.line, &len, var.file)) != -1)
	{
		var.lineNum++;

		opcode = strtok(var.line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			funopcodes(opcode, var.lineNum);
	}
}
