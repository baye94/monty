#include "monty.h"

/**
 * push - Pushes an item to the top of the stack
 * @num: The number to push
 */
void push(char *num)
{
	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", var.lineNum);
		funfree();
		exit(EXIT_FAILURE);
	}

	ValueDigit(num);

	Value_push(atoi(num));
}

/**
 * Value_push - pushes an int to the top of the stack
 * @elm: The number to be pushed
 */
void Value_push(int elm)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *tmp = var.stack;

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		funfree();
		exit(EXIT_FAILURE);
	}

	new->n = elm;

	if (!var.stack)
	{
		new->next = NULL;
		new->prev = NULL;
		var.stack = new;
	}
	else
	{
		if (var.isStack)
		{
			new->next = var.stack;
			new->prev = NULL;
			var.stack->prev = new;
			var.stack = new;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
			new->next = NULL;
		}
	}
}

/**
 * ValueDigit - validate string for umber
 * @num: variable to validate
 */
void ValueDigit(char *num)
{
	int x = 0;

	if (num[0] == '-')
		x++;

	for (; num[x]; x++)
	{
		if (!isdigit(num[x]))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
					var.lineNum);
			funfree();
			exit(EXIT_FAILURE);
		}
	}
}
