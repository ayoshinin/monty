#include "monty.h"
/**
* _execute -It executes the opcode
* @hdl: head linked list - (stack)
* @linum: line number
* @file: ptr to monty file
* @cont: line content
* Return: no return
*/
int _execute(char *cont, stack_t **hdl, unsigned int linum, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"stack", _stack},
				{"queue", _queue},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(cont, " \n\t");
	if (op && op[0] == '#')
		return (0);
	glob.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(hdl, linum);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", linum, op);
		fclose(file);
		free(cont);
		_free_stack(*hdl);
		exit(EXIT_FAILURE); }
	return (1);
}
