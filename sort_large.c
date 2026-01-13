/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:11:05 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/13 20:30:32 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_chunk(t_node **stack_a, t_node **stack_b,
	int *size_a, int median)
{
	if ((*stack_a)->value <= median)
	{
		pb(stack_a, stack_b);
		(*size_a)--;
		return (1);
	}
	else
	{
		ra(stack_a);
		return (0);
	}
}

static void	push_chunk_to_b(t_node **stack_a, t_node **stack_b,
	int *size_a, int median)
{
	int	initial_size;
	int	pushed;
	int	rotations;
	int	target_pushes;

	initial_size = *size_a;
	target_pushes = initial_size / 2;
	pushed = 0;
	rotations = 0;
	while (*size_a > 3 && pushed < target_pushes)
	{
		if (rotations >= initial_size)
			break ;
		if (push_chunk(stack_a, stack_b, size_a, median) == 1)
		{
			pushed++;
			rotations = 0;
		}
		else
			rotations++;
	}
}

static void	push_remaining_to_b(t_node **stack_a, t_node **stack_b,
	int *size_a, int *size_b)
{
	while (*size_a > 3)
	{
		pb(stack_a, stack_b);
		(*size_a)--;
		(*size_b)++;
	}
}

static void	push_all_back_to_a(t_node **stack_a, t_node **stack_b,
	int *size_a, int *size_b)
{
	t_cost	cost;

	while (*stack_b != NULL)
	{
		cost.size_a = *size_a;
		cost.size_b = *size_b;
		move_min_cost(stack_a, stack_b, &cost);
		(*size_a)++;
		(*size_b)--;
	}
}

void	sort_large(t_node **stack_a, t_node **stack_b)
{
	int	size_a;
	int	size_b;
	int	median;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	size_a = count_nodes(*stack_a);
	median = get_median_value(*stack_a, stack_a, stack_b, size_a);
	size_b = 0;
	push_chunk_to_b(stack_a, stack_b, &size_a, median);
	size_b = count_nodes(*stack_b);
	push_remaining_to_b(stack_a, stack_b, &size_a, &size_b);
	sort_3(stack_a);
	push_all_back_to_a(stack_a, stack_b, &size_a, &size_b);
	final_rotation(stack_a);
}
