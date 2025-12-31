/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:07:52 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*p;

	p = malloc(sizeof(t_node));
	if (p == NULL)
		return (NULL);
	p->value = val;
	p->next_node = NULL;
	return (p);
}

void	add_back(t_node **head, t_node *n_node)
{
	t_node	*tmp;

	if (head == NULL || n_node == NULL)
		return ;
	if (*head == NULL)
	{
		*head = n_node;
		return ;
	}
	tmp = *head;
	while (tmp->next_node != NULL)
		tmp = tmp->next_node;
	tmp->next_node = n_node;
}

void	swap_nodes(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (head == NULL || *head == NULL || (*head)->next_node == NULL)
		return ;
	first = *head;
	second = first->next_node;
	first->next_node = second->next_node;
	second->next_node = first;
	*head = second;
}

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (head == NULL || *head == NULL || (*head)->next_node == NULL)
		return ;
	first = *head;
	last = *head;
	*head = first->next_node;
	while (last->next_node)
		last = last->next_node;
	last->next_node = first;
	first->next_node = NULL;
}

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*tmp;

	if (head == NULL || *head == NULL || (*head)->next_node == NULL)
		return ;
	last = NULL;
	tmp = *head;
	while (tmp->next_node != NULL)
	{
		last = tmp;
		tmp = tmp->next_node;
	}
	last->next_node = NULL;
	tmp->next_node = *head;
	*head = tmp;
}
