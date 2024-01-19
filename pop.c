#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/**
 * pop - it removes the last item added to the top of the stack
 * reducing its size by one
 * stack - it is a container of objects that are inserted and
 * removed according to the last-in first-out (LIFO) principle
 */

int stack[STACK_SIZE];
int top = -1;

void pop(void)
{
	if (top == -1)
	{
		fprintf(stderr, "Error: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		top--;
	}
}

int mian(void)
{
	pop();

	return (0);
}
