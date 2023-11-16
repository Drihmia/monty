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

