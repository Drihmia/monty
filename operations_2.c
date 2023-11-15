#include "monty.h"
/**
 * free_stack - frees a stack_t list.
 * @head: head of the list.
 * Return: None
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * delete_dnodeint_at_index - deletes the node at index index of a DL list.
 * @head: head of the list.
 * @index: is the index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *h = *head, *tmp;

	if (!head || !h)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		if ((*head)->next != NULL)
			(*head)->next->prev = NULL;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	tmp = get_dnodeint_at_index(h, index);
	if (!tmp)
		return (-1);
	if (tmp->next == NULL)
	{
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
	}
	return (1);
}

/**
 * get_dnodeint_at_index - get the node at the index n.
 * @head: head of the list.
 * @index:  is the index of the node, starting from 0.
 * Return:  the nth node of a stack_t linked list
 * or NULL if the node does not exist.
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);
	while (head)
	{
		if (index == i)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}

