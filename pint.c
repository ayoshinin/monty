#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/**
 * main - Code to push values onto the stack
 * push - Pushes a value onto the stack
 * stack - it is a container of objects that are inserted and
 * removed according to the last-in first-out (LIFO) principle
 * stack_size - it determines the amount of memory
 * available for storing function
 * @value: The value to be pushed onto the stack
 * pint - it checks if the stack is empty and prints the value at the top
 * if not empty it prints the eror message.
 */

void push(int value);
void pint(void);

int main(void)
{
	push(5); /* Push value onto the stack */

	pint(); /* Call the pint opcode */

	return (0);
}

/**
 * push - Pushes a value onto the stack
 * @value: The value to be pushed onto the stack
 */
void push(int value)
{
	static int SP = -1;

	if (SP < (STACK_SIZE - 1))
	{
		fprintf(stderr, "Error: Stack overflow");
		exit(EXIT_FAILURE);
	}
}

/**
 * pint - Prints the top value of the stack
 */
void pint(void)
{
	static int SP = -1;

	if (SP < 0)
	{
		fprintf(stderr, "Error: can't pint, stack empty");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", stack[SP]);
	}
}
