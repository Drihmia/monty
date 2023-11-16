#include "monty.h"

/**
 * wrapper - selects the correct function to perform the
 * instruction asked by the user.
 * @op_arg: struct (read monty.h for details)
 * Return: pointer to function depending on the operator chosen by the user.
 */
void (*wrapper(opt_arg * op_arg))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	generic_t ops[] = {
		{"pall", (void(*)(void))pall},
		{"pint", (void(*)(void))pint},
		{"pop", (void(*)(void))pop},
		{"push", (void(*)(void))push},
		{"stack", (void(*)(void))_stack},
		{"queue", (void(*)(void))queue},
		{"swap", (void(*)(void))swap},
		{"add", (void(*)(void))add},
		{"sub", (void(*)(void))sub},
		{"mul", (void(*)(void))mul},
		{"div", (void(*)(void))_div},
		{"mod", (void(*)(void))mod},
		{"pchar", (void(*)(void))pchar},
		{"rotr", (void(*)(void))rotr},
		{"nop", (void(*)(void))nop},
		{"pstr", (void(*)(void))pstr},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, op_arg->opcode))
		{
			if (!strcmp(op_arg->opcode, "push"))
			{
				(((push_t *)ops)[i]).f(&op_arg->stack, op_arg->line_number, op_arg->num);
				return (NULL);
			}
			return (((instruction_t *)ops)[i].f);
		}
		i++;
	}

	unkn(&op_arg->stack, op_arg->line_number, op_arg->opcode);
	return (NULL);
}

/**
 * push - push an element to the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * @num: the string that shoud hold an integer the data.
 * Return: 1 on failure and 0 on success.
 */
void push(stack_t **stack, unsigned int line_number, char *num)
{
	int n = 0;

	if (!num)
	{
		print_error("usage: push integer", line_number);
		errno = 1;
		return;
	}

	n = _atoi(num);

	if (errno)
	{
		/* sth wrong happened in _atoi */
		print_error("usage: push integer", line_number);
		return;
	}

	if (!strcmp(Mode, "stack"))
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}
/**
 * pall - print all  elements of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	print_stack(*stack);
}
/**
 * pint - print all integers of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		print_error("can't pint, stack empty", line_number);
		errno = 2;
		return;
	}
	print_stack(*stack);
}
/**
 * pop - remove an element from the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		print_error("can't pop an empty stack", line_number);
		errno = 2;
		return;

	}
	delete_dnodeint_at_index(stack, 0);
}

