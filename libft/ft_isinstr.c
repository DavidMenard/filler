/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 10:36:16 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/18 10:48:29 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinstr(const char *haystack, const char *needle)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!haystack || !needle)
		return (0);
	if (needle[0] == '\0')
	{
		return (0);
	}
	while (haystack[i] != '\0')
	{
		while (haystack[i + a] == needle[a])
		{
			a++;
			if (needle[a] == '\0')
				return (1);
		}
		a = 0;
		i++;
	}
	return (0);
}
