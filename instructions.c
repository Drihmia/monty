#include "monty.h"

/**
 * get_op_func - selects the correct function to perform the
 * instruction asked by the user.
 * @s: string.
 * Return: pointer to fu:xnction depending on the oprater chosen by the user.
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"stack", _stack},
		{"queue", queue},
		{"unkn", unkn},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, s))
			return (ops[i].f);
		i++;
	}
	return (ops[i - 1].f);

	return (NULL);
}

/**
 * nop - opcode nop doesn’t do anything.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(*stack);
	stack_t *tmp;
	(void)line_number;

	if (len < 2)
	{
		/* TODO: handle error msg */
		print_error("can't add, stack too short\n");
		errno = 1;
		return;
	}
	tmp = *stack;
	(*stack)->next->n += (*stack)->n;
	(*stack)->next->prev = 0;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * swap - swap
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(*stack);
	stack_t *tmp;
	(void)line_number;

	if (len < 2)
	{
		/* TODO: exit handler(free(cmd_line, stack), print, exit status)*/
		print_error("can't swap, stack too short\n");
		errno = 1;
		return;
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = 0;
	tmp->next = *stack;
	*stack = tmp;
}
/**
 * push - push an element to the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * @num: the string that shoud hold an integer the data.
 * Return: 1 on failure and 0 on success.
 */
int push(stack_t **stack, unsigned int line_number, char *num)
{
	int n = 0;

	(void) line_number;
	if (num)
		n = _atoi(num);
	else
		errno = 1;
	if (errno == 1)
	{
		char buf[3];

		sprintf(buf, "%d", line_number);
		print_error("L");
		print_error(buf);
		print_error(": usage: push integer\n"), errno = 0;
		return (1);
	}
	if (!strcmp(Mode, "stack"))
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
	return (0);
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
		char buf[3];


		sprintf(buf, "%d", line_number);
		print_error("L");
		print_error(buf);
		print_error(": can't pint, stack empty\n"), errno = 2;
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
		char buf[3];


		sprintf(buf, "%d", line_number);
		print_error("L");
		print_error(buf);
		print_error(": can't pop an enpty stack\n"), errno = 2;
		return;

	}
	delete_dnodeint_at_index(stack, 0);
}

