#include "monty.h"
/**
 * _mul - It multiplies the top two elements of the stack.
 * @hdl: head stack
 * @linum: line_number
*/
void _mul(stack_t **hdl, unsigned int linum)
{
	stack_t *sht;
	int len = 0, alt;

	sht = *hdl;
	while (sht)
	{
		sht = sht->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", linum);
		fclose(glob.file);
		free(glob.cont);
		_free_stack(*hdl);
		exit(EXIT_FAILURE);
	}
	sht = *hdl;
	alt = sht->next->n * sht->n;
	sht->next->n = alt;
	*hdl = sht->next;
	free(sht);
}

