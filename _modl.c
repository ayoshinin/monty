#include "monty.h"
/**
 * _mod - it computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @hdl: head stack
 * @linum: line number
*/
void _mod(stack_t **hdl, unsigned int linum)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", linum);
		fclose(glob.file);
		free(glob.cont);
		_free_stack(*hdl);
		exit(EXIT_FAILURE);
	}
	sht = *hdl;
	if (sht->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linum);
		fclose(glob.file);
		free(glob.cont);
		_free_stack(*hdl);
		exit(EXIT_FAILURE);
	}
	alt = sht->next->n % sht->n;
	sht->next->n = alt;
	*hdl = sht->next;
	free(sht);
}
