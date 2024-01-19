#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct
{
	int stack[STACK_SIZE];
	int top;
}
Stack;

void push(Stack *stack, int value)
{
	if (stack->top == STACK_SIZE)
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack->stack[stack->top++] = value;
}

void pall(Stack *stack)
{
	int i;
	for (i = stack->top - 1; i >= 0; i--)
	{
		printf("%d\n", stack->stack[i]);
	}
}

int main()
{
	Stack stack;
	stack.top = 0;
	
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);

	pall(&stack);
	return 0;
}
