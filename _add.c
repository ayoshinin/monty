#include "monty.h"
/**
 * _add - It adds the top two elements of the stack.
 * @hdl: head stack.
 * @linum: number_line
*/
void _add(stack_t **hdl, unsigned int linum)
{
	stack_t *alt;
	int len = 0, sht;

	alt = *hdl;
	while (alt)
	{
		alt = alt->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linum);
		fclose(glob.file);
		free(glob.cont);
		_free_stack(*hdl);
		exit(EXIT_FAILURE);
	}
	alt = *hdl;
	sht = alt->n + alt->next->n;
	alt->next->n = sht;
	*hdl = alt->next;
	free(alt);
}

