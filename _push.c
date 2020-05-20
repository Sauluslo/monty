#include "monty.h"
/**
 * _push - function is used to insert an element at the top of the stack.
 * @head: pointer to first element of the stack.
 * @value: element to insert.
 *
 * Return: add new element to stack.
*/
void _push(stack_t **head, unsigned int value)
{
	stack_t *top;
	(void)value;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = global.push_argv;
	top->next = *head;
	top->prev = NULL;
	if (*head != NULL)
		(*head)->prev = top;
	*head = top;
}
/**
 * add_dnodeint - function that adds a new node at the beginning
 * of a stack_t list.
 * @head: pointer head of the DLL
 * @n: const int
 *
 * Return: New node and if is failure NULL
*/
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp, *new = malloc(sizeof(stack_t));
	(void)n;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		/**
		 * Free the past allocs in stack
		*/
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	new->n = global.push_argv;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	temp = *head;
	new->next = temp;
	temp->prev = new;
	*head = new;
}
