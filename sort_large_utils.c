/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:00:00 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_index(t_node *stack_a, int value_b)
{
	t_node	*curr;
	int		target;
	int		best;
	int		idx;

	if (stack_a == NULL)
		return (-1);
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
	if (size == 0)
		return (0);
	if (index * 2 < size)
		return (index);
	return (size - index);
}

int	calc_total_cost(int idx_b, int idx_a, int size_b, int size_a)
{
	int	cost_b;
	int	cost_a;
	int	same_dir;

	cost_b = get_cost(idx_b, size_b);
	cost_a = get_cost(idx_a, size_a);
	same_dir = (idx_b * 2 < size_b) == (idx_a * 2 < size_a);
	if (same_dir)
	{
		if (cost_b > cost_a)
			return (cost_b);
		return (cost_a);
	}
	return (cost_b + cost_a);
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_cost *cost, int dir)
{
	while (cost->cost_a > 0 && cost->cost_b > 0)
	{
		if (dir)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		(cost->cost_a)--;
		(cost->cost_b)--;
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
