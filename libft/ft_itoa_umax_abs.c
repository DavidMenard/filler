/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_umax_abs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:48:30 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/06 13:51:55 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_umax_abs(uintmax_t n)
{
	char		*str;
	int			len;
	uintmax_t	nc;

	len = 2;
	nc = n;
	while (nc /= 10)
		len++;
	if (!(str = (char*)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
