#include "monty.h"

/**
 * print_stack - prints all the elements of a stack_t list.
 * @h: head of doubly linked list.
 * Return: the number of nodes.
 */
size_t print_stack(const stack_t *h)
{
	int i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * stack_len - mesure the lenght of a doubly linked list.
 * @h: head of the list.
 * Return: the number of elements in a linked stack_t list.
 */
size_t stack_len(const stack_t *h)
{
	int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: pointer to the head pointer of the dl list.
 * @n: integer (data).
 * Return: pointer the new created node.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (!*head)
	{
		*head = new;
	}
	else
	{
		new->next = (*head);
		(*head)->prev = new;
		*head = new;
	}
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: pointer to the head pointer of the dl list.
 * @n: integer (data).
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = NULL, *tmp = NULL;

	if (!head)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (!(*head))
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

/**
 * insert_dnodeint_at_index - nserts a new node at a given position.
 * @h: pointer to the head pointer of the DLL.
 * @idx: is the index of the list where the new node should be added.
 * Index starts at 0.
 * @n: integer (data).
 *
 * if it is not possible to add the new node at index idx,
 * do not add the new node and return NULL.
 * Return: the address of the new node, or NULL if it failed.
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	stack_t *he = NULL, *new = NULL;

	if (!h)
		return (NULL);
	he = *h;
	while (he)
	{
		if (idx == i)
		{
			break;
		}
		if (he->next == NULL)
			break;
		i++;
		he = he->next;
	}

	if (idx > i + 1)
		return (NULL);
	if (!he || he->prev == NULL)
	{
		return (add_dnodeint(h, n));
	}
	else if (idx == i + 1)
	{
		return (add_dnodeint_end(h, n));
	}
	else
	{
		new = malloc(sizeof(*new));
		if (!new)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			return (NULL);
		}
		new->n = n, new->next = he, new->prev = he->prev;

		he->prev->next = new, he->prev = new;
		he = new;
	}

	return (new);
}


