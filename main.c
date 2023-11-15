#define _POSIX_C_SOURCE 200809L
#include "monty.h"
void help(void);
char *Mode = "stack";
int line_number = 1;

/**
 * main- Entry point.
 * @ac: counter variable.
 * @av: array of strings variable
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line, **cmd_line;
	size_t size_line = 1;
	stack_t *stack = NULL;
	int err = 0;

	if (ac == 2)
	{
		file = open_file(av[1]), line = malloc(1);
		while (getline(&line, &size_line, file) != -1)
		{
			if (strncmp(line, "#", 1) && strncmp(line, "nop", 3))
			{
				cmd_line = tokenize(line);
				if (cmd_line)
				{
					if (!strcmp(cmd_line[0], "push"))
						err = push(&stack, line_number, cmd_line[1]);
					else
						get_op_func(cmd_line[0])(&stack, line_number);
				}
				if (err == 1 || errno == 2 || errno == 3)
				{
					fclose(file), free(line), free_stack(stack), errno = 0;
					free_arr_str(cmd_line), exit(EXIT_FAILURE);
				}

				free_arr_str(cmd_line);
			}
			line_number++;
		}
		fclose(file), free(line), free_stack(stack);
	}
	else
	{
		print_error("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
/**
 * unkn - handle the case where the user enter unknown cmd opcode.
 * @stack: pointer to head of a DLL.
 * @line_number: line number.
 * Return: None.
 */
void unkn(stack_t **stack, unsigned int line_number)
{
	char buf[3];

	(void) stack;
	sprintf(buf, "%d", line_number);
	print_error("L");
	print_error(buf);
	print_error(": unknown instruction ");
	print_error("\n");
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

