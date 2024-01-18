#ifndef MONTY_HEAD
#define MONTY_HEAD

#define  _GNU_SOURCE
#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/* ****> Stack structure <**** */
/**
 * struct stack_s - A doubly linked list representation of a stack (or queue)
 * @n: int
 * @prev: pts to the previous element of the stack (or queue)
 * @next: pts to the next element of the stack (or queue)
 *
 * Description: A doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: handle the opcode function
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct glob_s - holds relevant progam information
 * @arg: ptr to string which holds argument information 
 * @file: ptr to monty file
 * @cont: ptr to string containing the line content
 * @lifi: flag to indicate change btn. stack & queue
 * ... whether an operation should be performed in stack-like
 * or queue-like manner
 *
 * Description: for sharing program values throughout (each file)
 */
typedef struct glob_s
{
	char *arg;
	FILE *file;
	char *cont;
	int lifi;
}  glob_t;
extern glob_t glob;  /*Global variable*/

int _execute(char *cont, stack_t **hdl, unsigned int linum, FILE *file);
void _addnode(stack_t **hdl, int n);
void _free_stack(stack_t *head);
void _addqueue(stack_t **hdl, int n);

void _push(stack_t **head, unsigned int linum);
void _pall(stack_t **head, unsigned int linum);
void _queue(stack_t **hdl, unsigned int linum);
void _pint(stack_t **hdl, unsigned int linum);
void _pop(stack_t **hdl, unsigned int linum);
void _swap(stack_t **hdl, unsigned int linum);
void _add(stack_t **hdl, unsigned int linum);
void _nop(stack_t **hdl, unsigned int linum);


void _sub(stack_t **hdl, unsigned int linum);
void _div(stack_t **hdl, unsigned int linum);
void _mul(stack_t **hdl, unsigned int linum);
void _mod(stack_t **hdl, unsigned int linum);
void _stack(stack_t **hdl, unsigned int linum);
#endif  /*MONTY_HEAD*/

