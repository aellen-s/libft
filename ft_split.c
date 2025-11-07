/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aellen-s <aellen-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:09:14 by aellen-s          #+#    #+#             */
/*   Updated: 2025/11/07 17:54:50 by aellen-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*str != '\0')
	{
		if (*str != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == c)
			i = 0;
		str++;
	}
	return (count);
}

static void	*free_strings(char **str, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(str[i++]);
	free(str);
	return (NULL);
}

static void	equal_zero(size_t *a)
{
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**new_strings;
	size_t	a[3];

	equal_zero(a);
	new_strings = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (new_strings == NULL)
		return (NULL);
	ft_memset(new_strings, 0, sizeof(char *) * (count_words(s, c) + 1));
	while (s[a[0]])
	{
		while (s[a[0]] == c)
			a[0]++;
		if (s[a[0]])
		{
			a[2] = a[0];
			while (s[a[0]] != c && s[a[0]])
				a[0]++;
			new_strings[a[1]] = ft_substr(s, a[2], a[0] - a[2]);
			if (!new_strings[a[1]])
				return (free_strings(new_strings, a[1]));
			a[1]++;
		}
	}
	new_strings[a[1]] = NULL;
	return (new_strings);
}
