/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:08:28 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **head)
{
	if (head == NULL || *head == NULL || (*head)->next_node == NULL)
		return ;
	if ((*head)->value > (*head)->next_node->value)
		sa(head);
}

static void	sort_3_case1(t_node **head, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(head);
	else if (first > second && second > third)
	{
		sa(head);
		rra(head);
	}
	else if (first > second && second < third && first > third)
		ra(head);
}

static void	sort_3_case2(t_node **head, int first, int second, int third)
{
	if (first < second && second > third && first < third)
	{
		sa(head);
		ra(head);
	}
	else if (first < second && second > third && first > third)
		rra(head);
}

void	sort_3(t_node **head)
{
	int	first;
	int	second;
	int	third;

	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->next_node == NULL)
		return ;
	if ((*head)->next_node->next_node == NULL)
	{
		sort_2(head);
		return ;
	}
	first = (*head)->value;
	second = (*head)->next_node->value;
	third = (*head)->next_node->next_node->value;
	sort_3_case1(head, first, second, third);
	sort_3_case2(head, first, second, third);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	min_pos;

	size = count_nodes(*stack_a);
	while (size > SORT_THREE_THRESHOLD)
	{
		min_pos = find_min_index(*stack_a);
		if (min_pos == -1)
			break ;
		rotate_to_pos(stack_a, min_pos, size, 'a');
		pb(stack_a, stack_b);
		size--;
	}
	sort_3(stack_a);
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
