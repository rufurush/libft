/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:30:24 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/10 15:48:17 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((unsigned char)c == '\0')
	{
		return ((char *)(s_len + s));
	}
	while (s_len >= 0)
	{
		if ((unsigned char)s[s_len] == (unsigned char)c)
		{
			return ((char *)(s_len + s));
		}
		s_len--;
	}
	return (NULL);
}
