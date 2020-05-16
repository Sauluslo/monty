#include "monty.h"
/**
 * main - program
 * @argc: number of argv that exist
 * @argv: entered arguments
 *
 * Return: always successful
*/
global_t global;
int main(int argc, char **argv)
{
	stack_t *head;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &head);
	return (0);
}