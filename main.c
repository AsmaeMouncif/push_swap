/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:07:43 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/08 18:01:32 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_by_size(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_5(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!process_multiple_args(&stack_a, av, ac))
	{
		free_nodes(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(stack_a))
	{
		free_nodes(&stack_a);
		return (0);
	}
	size = count_nodes(stack_a);
	sort_by_size(&stack_a, &stack_b, size);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
	return (0);
}
