/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:00:00 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/12 14:42:21 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_index(t_node *stack_a, int value_b)
{
	t_node	*curr;
	int		target;
	int		best;
	int		idx;

	curr = stack_a;
	target = -1;
	best = INT_MAX;
	idx = 0;
	while (curr)
	{
		if (curr->value > value_b && curr->value < best)
		{
			best = curr->value;
			target = idx;
		}
		curr = curr->next_node;
		idx++;
	}
	if (target == -1)
		return (find_min_index(stack_a));
	return (target);
}

int	get_cost(int index, int size)
{
	if (index * 2 < size)
		return (index);
	return (size - index);
}

int	calc_total_cost(int n_rotation_b, int n_rotation_a, int dir_b, int dir_a)
{
	int	same_dir;

	same_dir = (dir_b == dir_a);
	if (same_dir == 1)
	{
		if (n_rotation_b > n_rotation_a)
			return (n_rotation_b);
		return (n_rotation_a);
	}
	return (n_rotation_b + n_rotation_a);
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_cost *cost, int dir)
{
	while (cost->n_rotation_a > 0 && cost->n_rotation_b > 0)
	{
		if (dir)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		(cost->n_rotation_a)--;
		(cost->n_rotation_b)--;
	}
}

void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
