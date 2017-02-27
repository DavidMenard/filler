/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:12:36 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/09 18:13:48 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi_max(char *str)
{
	intmax_t	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\n' || *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	result *= sign;
	return (result);
}
