#include "monty.h"

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

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		print_error("can't pchar, stack empty", line_number);
		errno = 1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		print_error("can't pchar, value out of range", line_number);
		errno = 1;
		return;
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	tmp = *stack;

	while (tmp)
	{
		if ((tmp)->n == 0 || (tmp)->n < 0 || (tmp)->n > 127)
			break;

		printf("%c", (tmp)->n);
		(tmp) = (tmp)->next;
	}
	printf("\n");
}

/**
 * rotl -  rotates the stack to the top.
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 * Return: None.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ref = *stack, *mov = NULL;

	(void) line_number;

	if ((*stack) && (*stack)->next)
	{
		/* moving the head STACK forward by one node */
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;

		/* moving the head MOV to the last node */
		mov = *stack;
		while (mov->next)
		{
			mov = mov->next;
		}

		/* attatch the head REF (node to rotl) to the last node */
		mov->next = ref;
		ref->prev = mov;
		ref->next = NULL;
	}
}


/**
 * rotr - rotates the stack to the bottom.
 * Description: The last element of the stack,
 * becomes the top element of the stack
 * @stack: pointer to the header of DLL.
 * @line_number: the line number of the op command.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	for (; tail->next; tail = tail->next)
		;
	tail->prev->next = 0;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
}


