#include "monty.h"
global_t global;


/**
 * main - program
 * @argc: number of argv that exist
 * @argv: entered arguments
 *
 * Return: always successful
*/
int main(int argc, char **argv)
{
	stack_t *head;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &head);
	free_dlistint(head);
	return (0);
}

/**
 * free_dlistint - function that free a stack_t list.
 * @head: pointer head of a DLL.
 *
 * Return: void, function free allocated memory on head.
*/
void free_dlistint(stack_t *head)
{
	stack_t *tempo;

	while (head != NULL)
	{
		tempo = head;
		head = head->next;
		free(tempo);
	}
}
