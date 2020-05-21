#include "monty.h"
/**
 * read_file - function that read a file
 * @file_name: name of the file
 * @head: pointer
 *
 * Return: None
*/
void read_file(char *file_name, stack_t **head)
{
	char *instruction;
	int aux_close, read;
	size_t bufsize = 0;
	instruct_func process;

	global.count_line = 1;
	global.file = fopen(file_name, "r");

	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((read = (getline(&global.buffer, &bufsize, global.file))) != -1)
	{
		instruction = parse_line_out(global.buffer, head);
		if (instruction == NULL)
		{
			global.count_line++;
			continue;
		}
		process = get_func(instruction);
		if (process == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", global.count_line, instruction);
			fclose(global.file);
		    free_dlistint(*head);
		    free(global.buffer);
			exit(EXIT_FAILURE);
		}
		process(head, global.push_argv);
		global.count_line++;
	}
	free(global.buffer);
	aux_close = fclose(global.file);
	if (aux_close == -1)
	{
		exit(-1);
	}
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
*/
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line_out - parse line
 * @line: line of the file
 * @head: first argument of the stack
 * @count_line: Count line in position
 *
 * Return: none
*/
char *parse_line_out(char *line, stack_t **head)
{
	char *op_code, *push, *argv;
	(void)head;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		argv = strtok(NULL, "\n ");
		if (isnumber(argv) == 1 && argv != NULL)
		{
			global.push_argv = atoi(argv);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", global.count_line);
			fclose(global.file);
		    free_dlistint(*head);
		    free(global.buffer);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}

/**
 * _isdigit - check the code for Holberton School students.
 * @c: the character c
 * Return: Always 0.
*/
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
