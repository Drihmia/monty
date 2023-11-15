#include "monty.h"

/**
 * get_op_func - selects the correct function to perform the
 * instruction asked by the user.
 * @s: string.
 * Return: pointer to fu:xnction depending on the oprater chosen by the user.
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	op_t ops[] = {
		{"push", push},
		{"pull", pull},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0, len = 0;

	while (i < 16)
	{
		if (!ops[i].op[0])
			return;
		len = strlen(ops[i].op[0]);
		if (strcmp(ops[i].op[0], s) && s[len] == '\0')
		{
			return (ops[i].f);
		}
		i++;
	}
	print_error("L");
	print_error(line_number);
	print_error(": unknown instruction ");
	print_error(s);
	print_error("\n");
	exit(EXIT_FAILURE);
}
