/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoihexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:41:29 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/26 14:47:41 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoihexa(char *str)
{
	int result;

	result = 0;
	while (ft_ishexa(*str))
	{
		result *= 16;
		if (ft_isdigit(*str))
			result += (*str) - '0';
		else if (*str > 91)
			result += (*str) - 'a' + 10;
		else
			result += (*str) - 'A' + 10;
		str++;
	}
	return (result);
}
