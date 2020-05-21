#include "monty.h"
/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 *
*/
void _pint(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *iterator;

	iterator = *stack;
	if (iterator == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", global.count_line);
		fclose(global.file);
		free_dlistint(*stack);
		free(global.buffer);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", iterator->n);
}
