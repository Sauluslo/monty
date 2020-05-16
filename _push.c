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
 * of a dlistint_t list.
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
		free_dlistint(new);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return;
	}
	temp = *head;
	new->next = temp;
	temp->prev = new;
	*head = new;
	free_dlistint(*head);
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

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tempo = head;
		free(tempo);
		head = head->next;
	}
}