#include "sort.h"
#include <stdlib.h>

/*
 * insertion_sort_list - sorts doubly linked list using insertion sort
 * @list: list to sort
 * Return: no return
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *node_next, *tmp, *node_nextnext;

	if (!list)
		return;

	node = *list;
	while (node->next)
	{
		node_next = node->next;
		if (node->n > node_next->n)
		{
			tmp = node->prev;
			if (node_next->next)
			{
				node_nextnext = node_next->next;
				node_nextnext->prev = node_next;
			}
			node->prev = node_next;
			node->next = node_next->next;
			node_next->prev = tmp;
			node_next->next = node;
			tmp->next = node_next;
			print_list(*list);
			check_prev(list, &node_next);
		}
		else
		{
			node = node->next;
		}
	}
}

/*
 * check_prev - checks all previous nodes
 * @list: list to sort
 * @next_node: list to check previous nodes
 * Return: no return
 **/

void check_prev(listint_t **list, listint_t **next_node)
{
	listint_t *node = *next_node, *node_prev, *tmp, *node_prevprev;

	while (node->prev)
	{
		node_prev = node->prev;
		if (node->n < node_prev->n)
		{
			tmp = node->next;
			if (node_prev->prev)
			{
				node_prevprev = node_prev->prev;
				node_prevprev->next = node;
			}
			else
			{
				*list = node;
			}
			node->prev = node_prev->prev;
			node->next = node_prev;
                        node_prev->prev = node;
                        node_prev->next = tmp;
			tmp->prev = node_prev;
                        print_list(*list);
		}
		else
		{
			node = node->prev;
		}
	}
}
