/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:21:25 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/05 21:08:35 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	while (dest[i] && i < size)
		i++;
	while (src[a] && (i + a) < (size - 1))
	{
		dest[i + a] = src[a];
		a++;
	}
	if (i < size)
		dest[i + a] = 0;
	return (i + ft_strlen(src));
}
