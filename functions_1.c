#include "monty.h"

/**
 * tokenize - tokenize each line of the opcode.
 * @line: the line
 * @cmd_line: the array to hold the tokens from @line
 * Return: array of string,
 */
char **tokenize(char *line, char **cmd_line)
{
	if (!line)
		return (NULL);

	cmd_line[0] = strtok(line, " \n\t");
	cmd_line[1] = strtok(NULL, " \n\t");
	cmd_line[2] = NULL;

	return (cmd_line);
}

/**
 * free_arr_str - freeing an array of strings.
 * @arr_str: array of strings.
 * Return: None.
 */
void free_arr_str(char **arr_str)
{
	int i = 0;

	if (arr_str)
	{
		while (arr_str[i])
			free(arr_str[i]), i++;

		free(arr_str);
	}
}
/**
 * open_file - open a file.
 * @file_name: the file name as a string.
 * Return: file stream.
 */
FILE *open_file(char *file_name)
{
	FILE *file = NULL;

	file = fopen(file_name, "r");
	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (file);
}
/**
 * print_error - print errors to stderr.
 * @string: string to address to stder.
 * @line_number: line number from opcode
 * Return: None.
 */
void print_error(char *string, int line_number)
{
	dprintf(STDERR_FILENO, "L%d: %s\n", line_number, string);
}


