/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:07:29 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(long result, int sign, char digit)
{
	if (sign == 1 && (result > LONG_MAX / 10
			|| (result == LONG_MAX / 10
				&& (digit - '0') > LONG_MAX % 10)))
		return (1);
	if (sign == -1 && (result > -(LONG_MIN / 10)
			|| (result == -(LONG_MIN / 10)
				&& (digit - '0') > -(LONG_MIN % 10))))
		return (1);
	return (0);
}

static void	init_atoi(const char *str, int *i, int *sign)
{
	*i = 0;
	*sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

long	ft_atoi_long(const char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	init_atoi(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(result, sign, str[i]))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
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
