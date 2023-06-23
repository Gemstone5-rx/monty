#include "monty.h"

/**
 * pall - print all elements of stack starting from the top (head)
 *
 * @stack: head of stack
 * @line_number: line number
 *
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number;

	current = *stack;

	if (current == NULL)
		return;

	if (current != NULL)
	{
		while (current)
		{
			printf("%d\n", current->n);

			current = current->next;
		}
	}
}

/**
 * pint - Function to print a stack
 *
 * @stack: head of stack
 * @line_number: ...
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		error_type(PINT_ERROR, NULL, line_number, NULL);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Function to remove an item from a stack
 *
 * @stack: head of stack
 * @line_number: ...
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *current = *stack;
	stack_t *temp = current;

	if (*stack == NULL)
		error_type(POP_ERROR, NULL, line_number, NULL);

	if (current->next != NULL)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = temp->prev;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}

/**
 * push - add node at beginning of linked list (stack)
 *
 * @stack: head of the linked list
 * @parameter: nodes data (int)
 *
 * Return: nada
 */
void push(stack_t **stack, unsigned int parameter)
{
	stack_t *current = NULL;
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		error_type(MALLOC_FAIL, NULL, 0, NULL);

	current = *stack;
	new_node->n = parameter;

	/* check if list is empty */
	if (current == NULL)
	{
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}
	/* else if list is not empty */
	new_node->next = current;
	new_node->prev = (*stack)->prev;
	(*stack)->prev = new_node;
	*stack = new_node;
}
