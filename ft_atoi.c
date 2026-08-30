/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:32:34 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/10 18:55:38 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow(long r, int d, int s)
{
	if (s == 1)
	{
		if (r > INT_MAX / 10 || (r == INT_MAX / 10 && d > 7))
			return (INT_MAX);
	}
	else
	{
		if (r > -(long)INT_MIN / 10
			|| (r == -(long)INT_MIN / 10 && d > 8))
			return (INT_MIN);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	int		sign;
	int		digit;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i++] - '0';
		if (ft_check_overflow(result, digit, sign))
			return (ft_check_overflow(result, digit, sign));
		result = result * 10 + digit;
	}
	return ((int)(result * sign));
}

//int	main(void)
//{
//	char	*test1;
//	char	*test2;
//	int		result;
//
//	test1 = "2365743568734568374345834756834756";
//	test2 = "-28345654723333333333333333547354735437";
//	result = ft_atoi(test1);
//	printf("%d", result);
//}
