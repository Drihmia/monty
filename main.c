#include "monty.h"
void help(void);
char *Mode = "stack";

/**
 * main- Entry point.
 * @ac: counter variable.
 * @av: array of strings variable
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line = NULL, *cmd_line[ARGS_SIZE];
	size_t size_line = 1;
	void (*op_func)(stack_t **stack, unsigned int line_number);
	opt_arg op_arg = {NULL, 1, 0, 0};

	if (ac == 2)
	{
		file = open_file(av[1]);
		while (getline(&line, &size_line, file) != -1)
		{
			if (tokenize(line, cmd_line) && cmd_line[0] && strncmp(cmd_line[0], "#", 1))
			{
				op_arg.opcode = cmd_line[0], op_arg.num = cmd_line[1];
				op_func = wrapper(&op_arg);
				if (op_func)
					op_func(&op_arg.stack, op_arg.line_number);

				if (errno)
				{
					/*TODO: abstract this to separate function */
					fclose(file);
					free(line);
					free_stack(op_arg.stack);
					errno = 0;
					exit(EXIT_FAILURE);
				}

			}
			op_arg.line_number++;
		}
		fclose(file), free(line), free_stack(op_arg.stack);
	}
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
/**
 * unkn - handle the case where the user enter unknown cmd opcode.
 * @stack: pointer to head of a DLL.
 * @line_number: line number.
 * @opcode: operation code string
 * Return: None.
 */
void unkn(stack_t **stack, unsigned int line_number, char *opcode)
{
	(void) stack;
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);

	errno = 3;
}

/**
 * _stack-  chose the mode stack
 * @stack: pointer to head of a DLL.
 * @line_number: line number.
 * Return: None.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack, (void) line_number;
	Mode = "stack";
}

/**
 * queue-  chose the mode queue
 * @stack: pointer to head of a DLL.
 * @line_number: line number.
 * Return: None.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack, (void) line_number;
	Mode = "queue";
}

