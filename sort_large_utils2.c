/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:00:00 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_move_cost(t_cheapest_ctx ctx, t_cost *temp, int i)
{
	temp->target_idx = find_target_index(ctx.stack_a, ctx.stack_b->value);
	temp->cost_b = get_cost(i, ctx.size_b);
	temp->cost_a = get_cost(temp->target_idx, ctx.size_a);
	temp->dir_b = (i * 2 < ctx.size_b);
	temp->dir_a = (temp->target_idx * 2 < ctx.size_a);
	temp->total = calc_total_cost(i, temp->target_idx,
			ctx.size_b, ctx.size_a);
}

int	find_cheapest_move(t_cheapest_ctx ctx, t_cost *best)
{
	t_node	*curr;
	t_cost	temp;
	int		i;
	int		min_cost;

	curr = ctx.stack_b;
	min_cost = INT_MAX;
	i = 0;
	while (curr && i < ctx.size_b)
	{
		ctx.stack_b = curr;
		calc_move_cost(ctx, &temp, i);
		if (temp.total < min_cost)
		{
			min_cost = temp.total;
			*best = temp;
		}
		curr = curr->next_node;
		i++;
	}
	return (min_cost != INT_MAX);
}

void	do_rotate(t_node **stack_a, t_node **stack_b, t_cost *cost)
{
	if (cost->dir_a == cost->dir_b)
		rotate_both(stack_a, stack_b, cost, cost->dir_a);
	while (cost->cost_a > 0)
	{
		if (cost->dir_a)
			ra(stack_a);
		else
			rra(stack_a);
		(cost->cost_a)--;
	}
	while (cost->cost_b > 0)
	{
		if (cost->dir_b)
			rb(stack_b);
		else
			rrb(stack_b);
		(cost->cost_b)--;
	}
}

void	execute_cheapest_move(t_node **stack_a, t_node **stack_b,
	int size_a, int size_b)
{
	t_cost			best_cost;
	t_cheapest_ctx	ctx;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	ctx.stack_a = *stack_a;
	ctx.stack_b = *stack_b;
	ctx.size_a = size_a;
	ctx.size_b = size_b;
	if (!find_cheapest_move(ctx, &best_cost))
		return ;
	do_rotate(stack_a, stack_b, &best_cost);
	pa(stack_a, stack_b);
}

int	get_median_value(t_node *stack, int size)
{
	int		*arr;
	int		median;
	t_node	*curr;
	int		i;

	if (stack == NULL || size <= 0)
		return (INT_MIN);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (INT_MIN);
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
