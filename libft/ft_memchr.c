/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:52:07 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/05 21:28:18 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	target;
	unsigned char	*src;

	src = (unsigned char*)str;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == target)
		{
			return ((void*)src + i);
		}
		i++;
	}
	return (NULL);
}
