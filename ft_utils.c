/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:07:29 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/13 20:32:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > INT_MAX)
			return (result);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	array = malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	return (extract_words(array, s, c));
}
