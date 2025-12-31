/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:00:00 by asmounci          #+#    #+#             */
/*   Updated: 2025/12/29 17:00:00 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array, size_t index)
{
	while (index > 0)
		free(array[--index]);
	free(array);
}

char	**extract_words(char **array, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		len = word_length(&s[j], c);
		if (len > 0)
		{
			array[i] = ft_substr(&s[j], 0, len);
			if (array[i] == NULL)
			{
				free_array(array, i);
				return (NULL);
			}
			j += len;
			i++;
		}
		else
			j++;
	}
	array[i] = NULL;
	return (array);
}

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
