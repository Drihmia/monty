#include "monty.h"



/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		print_error("can't add, stack too short", line_number);
		errno = 1;
		return;
	}
	(*stack)->next->n += (*stack)->n;

	tmp = *stack;
	(*stack)->next->prev = 0;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		print_error("can't sub, stack too short", line_number);
		errno = 1;
		return;
	}
	/* ----- sub's operation ----- */
	(*stack)->next->n -= (*stack)->n;

	/* ---- node's deletions ----- */
	tmp = *stack;
	(*stack)->next->prev = 0;
	*stack = (*stack)->next;
	free(tmp);
}


/**
 * _div - divides the top element of the stack from the second
 * top element of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		print_error("can't div, stack too short", line_number);
		errno = 1;
		return;
	}
	if (!(*stack)->n)
	{
		print_error("division by zero", line_number);
		errno = 1;
		return;
	}

	/* ----- div's operation ----- */
	(*stack)->next->n /= (*stack)->n;

	/* ---- node's deletions ----- */
	tmp = *stack;
	(*stack)->next->prev = 0;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * mul - multiply the top two elements of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		print_error("can't mul, stack too short", line_number);
		errno = 1;
		return;
	}
	tmp = *stack;
	tmp->next->n *= tmp->n;
	tmp->next->prev = 0;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mod - computes the rest of the division
 * Description: computes of the second top element of the stack,
 * by the top element of the stack.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		print_error("can't mod, stack too short", line_number);
		errno = 1;
		return;
	}
	if (!(*stack)->n)
	{
		print_error("division by zero", line_number);
		errno = 1;
		return;
	}
	tmp = *stack;
	tmp->next->n %= tmp->n;
	tmp->next->prev = 0;
	*stack = tmp->next;
	free(tmp);
}
