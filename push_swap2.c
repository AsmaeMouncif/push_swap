/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:00:00 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_arguments(t_node **stack_a, char **args, int start)
{
	int	i;

	i = start;
	while (args[i] != NULL)
	{
		if (args[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if (!create_node_and_add(stack_a, args[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	count_valid_args(char **split_args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (split_args[i] != NULL)
	{
		if (split_args[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	process_single_argument(t_node **stack_a, char *arg)
{
	char	**split_args;
	int		result;

	split_args = ft_split(arg, ' ');
	if (split_args == NULL)
		return (0);
	if (count_valid_args(split_args) == 0)
	{
		free_split(split_args);
		return (0);
	}
	result = process_arguments(stack_a, split_args, 0);
	free_split(split_args);
	return (result);
}

int	process_multiple_args(t_node **stack_a, char **av, int ac)
{
	int	i;

	if (ac == 2)
		return (process_single_argument(stack_a, av[1]));
	i = 1;
	while (i < ac)
	{
		if (!process_single_argument(stack_a, av[i]))
			return (0);
		i++;
	}
	return (1);
}
