#include "monty.h"
/**
 * get_func - get function of one line.
 * @str: string get of one line
 *
 * Return: always successful instruct[i].f or NULL in case of FAILURE
*/
instruct_func get_func(char *str)
{
	int i;
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		/**{"sub", _sub},*/
		{NULL, NULL},
	};
	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}
