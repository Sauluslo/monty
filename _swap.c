#include "monty.h"
/**
 * _swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 */

void _swap(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *iterator;
	int temp;

	iterator = *stack;
	if (iterator == NULL || iterator->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", global.count_line);
		fclose(global.file);
		free_dlistint(*stack);
		free(global.buffer);
		exit(EXIT_FAILURE);
	}
	temp = iterator->n;
	iterator->n = iterator->next->n;
	iterator->next->n = temp;
}
