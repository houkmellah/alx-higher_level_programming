#include "lists.h"

/**
 * palindrom -  palind or not rescusive
 * @head: head of  list
 * Return: if isn't palindrom the function return 0
 * 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);
	return (aux_palind(head, *head));
}

/**
 * aux_palind - funct to detect a palindrome
 * @head: head of the list
 * @end: final element of the list 
 */
int aux_palind(listint_t **head, listint_t *end)
{
	if (end == NULL)
		return (1);
	if (aux_palind(head, end->next) && (*head)->n == end->n)
	{
		*head = (*head)->next;
		return (1);
	}
	return (0);
}

