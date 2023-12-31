#ifndef MONTY_
#define MONTY_
#define _GNU_SOURCE

/*Error Descriptors*/
#define MALLOC_FAIL 300
#define UNKNOWN_INSTRUCTION 301
#define NO_FILE_ERROR 302
#define PUSH_ERROR 303
#define PINT_ERROR 304
#define POP_ERROR 305
#define SWAP_ERROR 306
#define ADD_ERROR 307

#define SUB_ERROR 308
#define DIV_ERROR 309
#define DIV_ZERO_ERROR 310
#define MUL_ERROR 311
#define MOD_ERROR 312

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

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

/* stack declaration "global variable"*/
extern stack_t *head;

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

/*functions*/
void push(stack_t **stack, unsigned int parameter);
void pall(stack_t **stack, unsigned int line_number);
void (*select_operation(char *opcode_string))(stack_t **, unsigned int);
void free_stack(void);


int is_all_whitespace(char *str);

void error_type(int error_number, char *opcode, unsigned int line,
				 char *buffer);
void error_type2(int error_number, char *opcode, unsigned int line,
				  char *buffer);

void checker_1(const char *filename, int argc);

int is_digit(char *str);

void file_access(char *file_name);

void check_argv(const char *fil_ename, int argc);

int valid_opcode(char *opcode, char **valid_opcodes);


void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

void conditions(char *opcode, size_t line, char *parameter, char *buffer);
#endif
