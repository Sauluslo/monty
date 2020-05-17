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
	/*stack_t *aux;
	aux = (stack_t)malloc(sizeof(stack_t));
	aux->value = value;
	aux->next = (*head);
	(*head) = aux;*/
	add_dnodeint(head, value);
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

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		/* Free the past allocs in stack */
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	new->n = n;
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
