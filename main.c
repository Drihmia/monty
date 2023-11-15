#define _POSIX_C_SOURCE 200809L
#include "monty.h"

int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line, **cmd_line;
	size_t size_line = 1;
	int i = 1;

	if (ac == 2)
	{
		file = open_file(av[1]);
		line = malloc(1);
		printf("Has been opened the file\n");
		while (getline(&line, &size_line, file) != -1)
		{
			cmd_line = tokenize(line);
			if (cmd_line)
			{
				printf("the opcode :%s\n", cmd_line[0]);
				if(cmd_line[1])
					printf("the value : %s\n", cmd_line[1]);
				free_arr_str(cmd_line);
			}
			i++;
			printf("line N : %d\n", i);
		}
		fclose(file);
		free(line);
	}
	else
	{
		print_error("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

#if 0
	printf("line : %s\n", line);
	printf("token_1: %s\n", token_1);
	printf("werghjk\n");
#endif
