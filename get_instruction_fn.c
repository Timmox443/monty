#include "monty.h"
#include <string.h>

/**
 * do_instruction - get the function associated with an opcode
 * @opcode: the opcode to match
 *
 * Return: If opcode is NULL, return NULL. If match is found, return the
 * corresponding function. If match is not found, exit with EXIT_FAILURE.
 */
instruction_fn get_instruction_fn(const char *opcode)
{
	static instruction_t instructions[] = {
		{"add",   op_add},
		{"nop",   op_nop},
		{"pall",  op_pall},
		{"pint",  op_pint},
		{"pop",   op_pop},
		{"push",  op_push},
		{"swap",  op_swap},
		{"div",   op_div},
		{"mod",   op_mod},
		{"mul",   op_mul},
		{"pchar", op_pchar},
		{"pstr",  op_pstr},
		{"queue", op_queue},
		{"rotl",  op_rotl},
		{"rotr",  op_rotr},
		{"stack", op_stack},
		{"sub",   op_sub},
		{0}
	};
	instruction_t *op = instructions;

	if (opcode)
	{
		while (op->opcode)
		{
			if (!strcmp(opcode, op->opcode))
				return (op->fn);
			++op;
		}
		pfailure("L%u: unknown instruction %s\n", op_env.lineno, opcode);
	}
	return (NULL);
}
