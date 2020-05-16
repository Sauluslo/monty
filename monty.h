#ifndef MON_H
#define MON_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
    FILE *file;
    int push_argv;
    char *buffer;
} global_t;

extern global_t global;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);

int main(int argc, char **argv);
char *parse_line_out(char *line, stack_t **head, unsigned int count_line);
int _isdigit(int c);
int isnumber(char *str);
instruct_func get_func(char *str);
void read_file(char *file_name, stack_t **head);
void _push(stack_t **head, unsigned int value);
void add_dnodeint(stack_t **head, const int n);
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void free_dlistint(stack_t *head);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
int _isalpha(int c);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number);

#endif
