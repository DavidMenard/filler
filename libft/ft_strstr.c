/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:31:20 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/05 21:31:21 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (needle[0] == '\0')
	{
		return ((char*)haystack);
	}
	while (haystack[i] != '\0')
	{
		while (haystack[i + a] == needle[a])
		{
			a++;
			if (needle[a] == '\0')
				return ((char*)haystack + i);
		}
		a = 0;
		i++;
	}
	haystack = 0;
	return ((char*)haystack);
}
