/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:42:44 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/10 16:48:12 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	free_all(char **result, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(result[i++]);
	}
	free(result);
	return (0);
}

static char	*alloc_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	j;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < end)
		word[j++] = s[start++];
	word[j] = '\0';
	return (word);
}

static size_t	ft_splits_counts(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
		}
	}
	return (count);
}

static size_t	ft_split_fill(char **result, const char *s, char c,
		size_t split)
{
	size_t	i;
	size_t	index;
	size_t	start;

	i = 0;
	index = 0;
	while (index < split)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		result[index] = alloc_word(s, start, i);
		if (!result[index])
			return (free_all(result, index), 0);
		index++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	split;

	if (!s)
		return (NULL);
	split = ft_splits_counts(s, c);
	result = (char **)malloc(sizeof(char *) * (split + 1));
	if (!result)
		return (NULL);
	if (!ft_split_fill(result, s, c, split))
		return (NULL);
	result[split] = NULL;
	return (result);
}
