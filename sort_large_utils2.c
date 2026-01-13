/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:00:00 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/13 20:30:32 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_move_cost(t_node *stack_a, t_node *stack_b,
	t_cost *temp, int i)
{
	temp->position_index = find_target_index(stack_a, stack_b->value);
	temp->n_rotation_b = get_cost(i, temp->size_b);
	temp->n_rotation_a = get_cost(temp->position_index, temp->size_a);
	temp->direction_b = (i * 2 < temp->size_b);
	temp->direction_a = (temp->position_index * 2 < temp->size_a);
	temp->total_cost = calc_total_cost(temp->n_rotation_b, temp->n_rotation_a,
			temp->direction_b, temp->direction_a);
}

int	find_min_cost_move(t_node *stack_a, t_node *stack_b,
	t_cost *best)
{
	t_node	*curr;
	t_cost	temp;
	int		i;
	int		min_cost;

	curr = stack_b;
	min_cost = INT_MAX;
	i = 0;
	temp.size_a = best->size_a;
	temp.size_b = best->size_b;
	while (curr && i < best->size_b)
	{
		calc_move_cost(stack_a, curr, &temp, i);
		if (temp.total_cost < min_cost)
		{
			min_cost = temp.total_cost;
			*best = temp;
		}
		curr = curr->next_node;
		i++;
	}
	return (min_cost != INT_MAX);
}

void	do_rotate(t_node **stack_a, t_node **stack_b, t_cost *cost)
{
	if (cost->direction_a == cost->direction_b)
		rotate_both(stack_a, stack_b, cost, cost->direction_a);
	while (cost->n_rotation_a > 0)
	{
		if (cost->direction_a == 1)
			ra(stack_a);
		else
			rra(stack_a);
		(cost->n_rotation_a)--;
	}
	while (cost->n_rotation_b > 0)
	{
		if (cost->direction_b == 1)
			rb(stack_b);
		else
			rrb(stack_b);
		(cost->n_rotation_b)--;
	}
}

void	move_min_cost(t_node **stack_a, t_node **stack_b,
	t_cost *cost)
{
	find_min_cost_move(*stack_a, *stack_b, cost);
	do_rotate(stack_a, stack_b, cost);
	pa(stack_a, stack_b);
}

int	get_median_value(t_node *stack, t_node **stack_a,
	t_node **stack_b, int size)
{
	int		*arr;
	int		median;
	t_node	*curr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		free_nodes(stack_a);
		free_nodes(stack_b);
		write(2, "Error\n", 6);
		exit(1);
	}
	curr = stack;
	i = 0;
	while (curr && i < size)
	{
		arr[i++] = curr->value;
		curr = curr->next_node;
	}
	bubble_sort_array(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
