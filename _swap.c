#include "monty.h"
/**
 * _swap - It adds the top two elements of the stack.
 * @hdl: stack head
 * @linum: line number
*/
void _swap(stack_t **hdl, unsigned int linum)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", linum);
		fclose(glob.file);
		free(glob.cont);
		_free_stack(*hdl);
		exit(EXIT_FAILURE);
	}
	alt = *hdl;
	sht = alt->n;
	alt->n = alt->next->n;
	alt->next->n = sht;
}

