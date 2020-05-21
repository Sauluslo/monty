#include "monty.h"
/**
 * _swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator;
	int temp;

	iterator = *stack;
	if (iterator == NULL || iterator->next == NULL)
	{
		line_number += 1;
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free_dlistint(*stack);
		free(global.buffer);
		exit(EXIT_FAILURE);
	}
	temp = iterator->n;
	iterator->n = iterator->next->n;
	iterator->next->n = temp;
}
