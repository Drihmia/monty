#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* -----------ALIASES-----------*/
/* typedef struct stack_s stack_t; */

/* -----------MACROS-----------*/
#define ARGS_SIZE 3

/* -----------GLOBALS-----------*/
extern char *Mode;

/* -----------STRUCTS-----------*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct generic_s - generic struct to cast it later
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct generic_s
{
	char *opcode;
	void (*f)(void);
} generic_t;

/**
 * struct push_s - push
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct push_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, char *num);
} push_t;

/**
 * struct operations_s - operations arguments
 *
 * @opcode: the opcode
 * @line_number: the opcode
 * @num: the opcode
 * @stack: the opcode
 *
 * Description: opcode and its function
 */
typedef struct operations_s
{
	stack_t *stack;
	unsigned int line_number;
	char *num;
	char *opcode;
} opt_arg;

/* ---------------INSTRUCTIONS------------------ */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number, char *num);
void pull(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* utilities for manupilating the doubly linked list */

size_t print_stack(const stack_t *h);
size_t stack_len(const stack_t *h);

/* add node int */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);

void free_stack(stack_t *head);

/* pop or remove and node */
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

/* -----------UTILS---------*/
FILE *open_file(char *file_name);
char **tokenize(char *line, char **);
void free_arr_str(char **arr_str);
void (*wrapper(opt_arg * op_arg))(stack_t **stack, unsigned int line_number);

/* -----------errors-----------*/
void print_error(char *string, int line_number);
void unkn(stack_t **stack, unsigned int line_number, char *opcode);


/* -----------MOCKS-----------*/
int _isdigit(char);
int _atoi(char *);

#endif

