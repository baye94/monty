#include "monty.h"

var_t var;
/**
 * Funfree - Function to function to free
 * Return - Nothing, Function void
 */
void funfree(void)
{
	stack_t *item;

	while (var.stack)
	{
		item = var.stack->next;
		free(var.stack);
		var.stack = item;
	}

	free(var.line);

	fclose(var.file);
}
