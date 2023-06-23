#include "monty.h"
/**
 * error_type - Handle different error cases
 * @error_number: The error code indicating the type of error
 * @opcode: The opcode associated with the error (if applicable)
 * @line: The line number where the error occurred
 * @buffer: The buffer containing the input line (if applicable)
 */
void error_type(int error_number, char *opcode, unsigned int line,
		char *buffer)
{
	if (error_number > 307)
		error_type2(error_number, opcode, line, buffer);

	switch (error_number)
	{
		/* common errors*/
	case MALLOC_FAIL:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case UNKNOWN_INSTRUCTION:
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		break;
		/*logic errrors */
	case NO_FILE_ERROR:
		fprintf(stderr, "USAGE: Monty file\n");
		break;
	case PUSH_ERROR:
		fprintf(stderr, "L%d: usage: push integer\n", line);
		break;
	case PINT_ERROR:
		fprintf(stderr, "L%d: can't pint, stack is empty\n", line);
		break;
	case POP_ERROR:
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		break;
	case SWAP_ERROR:
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		break;
	case ADD_ERROR:
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		break;

	default:
		break;
	}

	free_stack();
	if (buffer)
		free(buffer);
	exit(EXIT_FAILURE);
}
/**
 * erro_type2 - Handle different error cases
 * @error_number: The error code indicating the type of error
 * @opcode: The opcode associated with the error (if applicable)
 * @line: The line number where the error occurred
 * @buffer: The buffer containing the input line (if applicable)
 */
void error_type2(int error_number, char *opcode, unsigned int line,
		 char *buffer)
{
	(void)opcode;
	/* advanced tasks */
	switch (error_number)
	{

	case SUB_ERROR:
		fprintf(stderr, "L%d: can't subtract, stack too short\n", line);
		break;
	case DIV_ERROR:
		fprintf(stderr, "L%d: can't divide, stack too short\n", line);
		break;
	case DIV_ZERO_ERROR:
		fprintf(stderr, "L%d: division by zero\n", line);
		break;
	case MUL_ERROR:
		fprintf(stderr, "L%d: can't multiply, stack too short\n", line);
		break;
	case MOD_ERROR:
		fprintf(stderr, "L%d: can't find modulus, stack too short\n", line);
		break;

	default:
		break;
	}

	free_stack();
	if (buffer)
		free(buffer);
	exit(EXIT_FAILURE);
}
