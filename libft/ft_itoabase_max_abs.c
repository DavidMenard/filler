/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_max_abs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 08:46:36 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/06 11:13:25 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sft_loadchar(char *str, size_t len, intmax_t value, int base)
{
	intmax_t	temp;

	while (len--)
	{
		temp = value % base;
		value /= base;
		if (temp <= 9)
			str[len] = temp + '0';
		else
			str[len] = temp + 'A' - 10;
	}
}

char			*ft_itoabase_max_abs(intmax_t value, int base)
{
	char		*str;
	size_t		len;
	intmax_t	temp;

	if (value == 0 || base <= 1)
		return (ft_strdup("0"));
	if (value < 0)
		value = -value;
	len = 2;
	temp = value;
	while (temp /= base)
		len++;
	if (!(str = (char*)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	sft_loadchar(str, len, value, base);
	return (str);
}
