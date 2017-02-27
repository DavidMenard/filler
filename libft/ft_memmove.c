/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:37:07 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/07 10:09:57 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned char	*temp;

	dest = (unsigned char*)str1;
	src = (unsigned char*)str2;
	temp = src;
	while (temp < src + n)
	{
		if (temp == dest)
		{
			temp = src + n - 1;
			while (temp >= src)
			{
				*(temp + (dest - src)) = *temp;
				temp--;
			}
			return (dest);
		}
		temp++;
	}
	return (ft_memcpy(str1, str2, n));
}
