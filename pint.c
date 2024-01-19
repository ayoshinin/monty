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

void pint(int *stack, int *stack_size)
{
        int top_value; /* Move variable declaration to the beginning */

        if (*stack_size == 0)
        {
                printf("L<line_number>: can't pint, stack empty\n");
                exit(EXIT_FAILURE);
        }
        top_value = stack[*stack_size - 1]; /* Assign the value */
        printf("%d\n", top_value); /* Print the value */
}
