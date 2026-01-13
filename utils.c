/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:08:34 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/13 17:52:56 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	if (tmp == NULL || tmp->next_node == NULL)
		return (1);
	while (tmp->next_node != NULL)
	{
		if (tmp->value > tmp->next_node->value)
			return (0);
		tmp = tmp->next_node;
	}
	return (1);
}

int	count_nodes(t_node *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next_node;
	}
	return (count);
}

int	find_min_index(t_node *head)
{
	t_node	*tmp;
	int		min;
	int		min_index;
	int		current_index;

	if (head == NULL)
		return (-1);
	tmp = head;
	min = tmp->value;
	min_index = 0;
	current_index = 0;
	while (tmp != NULL)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = current_index;
		}
		tmp = tmp->next_node;
		current_index++;
	}
	return (min_index);
}

void	rotate_to_pos(t_node **stack, int position, int size, char stack_n)
{
	int	rotations;

	if (position * 2 < size)
	{
		while (position > 0)
		{
			if (stack_n == 'a')
				ra(stack);
			else
				rb(stack);
			position--;
		}
	}
	else
	{
		rotations = size - position;
		while (rotations > 0)
		{
			if (stack_n == 'a')
				rra(stack);
			else
				rrb(stack);
			rotations--;
		}
	}
}

void	final_rotation(t_node **stack_a)
{
	int	size_a;
	int	min_idx;
	int	rotations;

	size_a = count_nodes(*stack_a);
	min_idx = find_min_index(*stack_a);
	if (min_idx == 0)
		return ;
	if (min_idx * 2 < size_a)
	{
		rotations = min_idx;
		while (rotations-- > 0)
			ra(stack_a);
	}
	else
	{
		rotations = size_a - min_idx;
		while (rotations-- > 0)
			rra(stack_a);
	}
}
