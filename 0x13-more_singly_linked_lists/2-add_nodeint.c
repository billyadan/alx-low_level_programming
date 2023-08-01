#include "lists.h"

/**
 * add_nodeint - adds new node at beginning of linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int x)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->x = x;
	new->next = *head;
	*head = new;

	return (new);
}
