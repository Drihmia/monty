#include "monty.h"

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
 * swap - swap
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		print_error("can't swap, stack too short", line_number);
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
