/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:15:00 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_node *head, int value)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next_node;
	}
	return (0);
}

static int	check_sign(char *str, int *i)
{
	int	sign_count;

	sign_count = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '\0')
		return (0);
	if (str[*i] == '+' || str[*i] == '-')
	{
		sign_count++;
		(*i)++;
	}
	if (sign_count > 0 && !ft_isdigit(str[*i]))
		return (0);
	return (1);
}

static int	validate_digits(char *str, int i)
{
	int	has_digit;

	has_digit = 0;
	while (str[i] != '\0' && str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (has_digit);
}

int	validate_argument(char *str)
{
	int		i;
	long	num;

	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	if (!check_sign(str, &i))
		return (0);
	if (!validate_digits(str, i))
		return (0);
	num = ft_atoi_long(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	create_node_and_add(t_node **stack_a, char *arg)
{
	long	value;
	t_node	*new;

	if (!validate_argument(arg))
		return (0);
	value = ft_atoi_long(arg);
	if (has_duplicate(*stack_a, (int)value))
		return (0);
	new = new_node((int)value);
	if (new == NULL)
	{
		free_nodes(stack_a);
		return (0);
	}
	add_back(stack_a, new);
	return (1);
}
