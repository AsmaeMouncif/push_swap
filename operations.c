/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:08:01 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/09 12:13:08 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
{
	swap_nodes(head);
	write(1, "sa\n", 3);
}

void	sb(t_node **head)
{
	swap_nodes(head);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next_node;
	tmp->next_node = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next_node;
	tmp->next_node = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}
