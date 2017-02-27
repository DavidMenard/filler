/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:29:34 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/05 21:28:39 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	deli;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	deli = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == deli)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
