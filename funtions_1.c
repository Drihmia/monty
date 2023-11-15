#include "monty.h"


char **tokenize(char *line)
{
	char *token_1, *token_2, **cmd_line;
	int a = 0;
	if (!line)
		return (NULL);
	token_1 = strtok(line, " \n\t\v\f\r");
	if (!token_1)
		return (NULL);
	token_2 = strtok(NULL, " \n\t\v\f\r");
	a = token_2 ? 3 : 2;
	cmd_line = malloc(a * sizeof(char *));

	cmd_line[0] = malloc(strlen(token_1) + 1);
	strcpy(cmd_line[0], token_1);
	if (a == 3)
	{
		cmd_line[1] = malloc(strlen(token_2) + 1);
		strcpy(cmd_line[1], token_2);
		cmd_line[2] = NULL;
	}
	else
		cmd_line[1] = NULL;
	return (cmd_line);
}
void free_arr_str(char **arr_str)
{
	int i = 0;
	while (arr_str[i])
		free(arr_str[i]), i++;
	free(arr_str);
}

FILE *open_file(char *file_name)
{
	FILE *file = NULL;

	file = fopen(file_name, "r");
	if (!file)
	{
		print_error("Error: Can't open file ");
		print_error(file_name);
		print_error("\n");
		exit(EXIT_FAILURE);
	}
	return (file);
}

void print_error(char *string)
{
	size_t size = strlen(string) + 1;

	write(2, string, size);
}


