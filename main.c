#include "monty.h"


/**
 * main - Monty code interpreter
 * @argc: No of args
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t line_size = 0;
	ssize_t read_result = 1;
	stack_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	glob.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_result > 0)
	{
		line_content = NULL;
		read_result = getline(&line_content, &line_size, monty_file);
		glob.cont = line_content;
		line_counter++;

		if (read_result > 0)
		{
			_execute(line_content, &stack, line_counter, monty_file);
		}

		free(line_content);
	}

	_free_stack(stack);
	fclose(monty_file);

	return (EXIT_SUCCESS);
}

