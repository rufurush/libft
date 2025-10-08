/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:17:49 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/10 16:38:40 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	calc_trim_length(const char *s, const char *set, size_t *start)
{
	size_t	end;
	size_t	len;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	end = len - 1;
	while (s[*start] && is_in_set(s[*start], set))
		(*start)++;
	while (end >= *start && is_in_set(s[end], set))
		end--;
	if (end < *start)
		return (0);
	return (end - *start + 1);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	trim_len;
	char	*result;
	size_t	i;
	size_t	malloc_size;

	if (!s || !set)
		return (NULL);
	start = 0;
	trim_len = calc_trim_length(s, set, &start);
	malloc_size = trim_len + 1;
	result = (char *)malloc(sizeof(char) * malloc_size);
	if (!result)
		return (NULL);
	i = 0;
	while (trim_len-- > 0)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
