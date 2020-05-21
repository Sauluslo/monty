#include "monty.h"
/**
 * _pop - remove element a list
 * @stack: pointer to first node
 * Return: void
*/
void _pop(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", global.count_line);
		fclose(global.file);
		free_dlistint(*stack);
		free(global.buffer);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}
