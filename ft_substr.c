/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:57:24 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/10 16:41:11 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substr_len(char const *s, size_t start, size_t len)
{
	size_t	src_len;
	size_t	avalable_len;

	src_len = ft_strlen(s);
	if (src_len <= start || len == 0)
	{
		return (0);
	}
	avalable_len = src_len - start;
	if (avalable_len <= len)
	{
		return (avalable_len);
	}
	else
	{
		return (len);
	}
}

static char	*ft_store_strings(char const *s, char *result, size_t start,
		size_t len)
{
	size_t		substr_len;
	const char	*substr_start;
	char		*temp;

	substr_len = ft_substr_len(s, start, len);
	temp = result;
	substr_start = s + start;
	while (substr_len > 0)
	{
		*temp = *substr_start;
		temp += 1;
		substr_start++;
		substr_len--;
	}
	*temp = '\0';
	return (result);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*result;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	substr_len = ft_substr_len(s, start, len);
	if (s_len <= start)
	{
		result = (char *)malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!result)
		return (NULL);
	ft_store_strings(s, result, start, len);
	return (result);
}
