/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:11:05 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_chunk(t_node **stack_a, t_node **stack_b,
	int *size_a, int median)
{
	if (*stack_a == NULL)
		return (0);
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

static void	smart_push_to_b(t_node **stack_a, t_node **stack_b,
	int *size_a, int median)
{
	int	initial_size;
	int	pushed;
	int	rotations;
	int	target_pushes;

	if (stack_a == NULL || *stack_a == NULL || size_a == NULL)
		return ;
	initial_size = *size_a;
	target_pushes = initial_size / 2;
	pushed = 0;
	rotations = 0;
	while (*size_a > 3 && pushed < target_pushes)
	{
		if (rotations >= initial_size)
			break ;
		if (push_chunk(stack_a, stack_b, size_a, median))
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
	while (*size_a > SORT_THREE_THRESHOLD)
	{
		pb(stack_a, stack_b);
		(*size_a)--;
		(*size_b)++;
	}
}

static void	push_all_back_to_a(t_node **stack_a, t_node **stack_b,
	int *size_a, int *size_b)
{
	while (*stack_b != NULL)
	{
		execute_cheapest_move(stack_a, stack_b, *size_a, *size_b);
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
	if (size_a <= SORT_FIVE_THRESHOLD)
	{
		if (size_a == 3)
			sort_3(stack_a);
		else if (size_a == 4 || size_a == 5)
			sort_5(stack_a, stack_b);
		return ;
	}
	median = get_median_value(*stack_a, size_a);
	if (median == INT_MIN)
		median = (*stack_a)->value;
	size_b = 0;
	smart_push_to_b(stack_a, stack_b, &size_a, median);
	size_b = count_nodes(*stack_b);
	push_remaining_to_b(stack_a, stack_b, &size_a, &size_b);
	sort_3(stack_a);
	push_all_back_to_a(stack_a, stack_b, &size_a, &size_b);
	final_rotation(stack_a);
}
