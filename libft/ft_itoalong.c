/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:52:11 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/03 13:54:49 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sft_isneg(int long *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoalong(int long n)
{
	char	*str;
	int		len;
	int		nc;
	int		neg;

	len = 2;
	neg = 0;
	sft_isneg(&n, &neg);
	nc = n;
	while (nc /= 10)
		len++;
	len += neg;
	if (!(str = (char*)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
