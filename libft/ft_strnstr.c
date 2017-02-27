/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:24:10 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/09 17:22:56 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!s2[0])
	{
		return ((char*)s1);
	}
	while (s1[i])
	{
		while (s1[i + a] == s2[a])
		{
			a++;
			if ((size_t)(i + a) > len)
				return (NULL);
			if (!s2[a])
				return ((char*)s1 + i);
		}
		a = 0;
		i++;
	}
	s1 = 0;
	return ((char*)s1);
}
