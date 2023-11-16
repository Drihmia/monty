#include "monty.h"


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
