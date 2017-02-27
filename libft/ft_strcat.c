/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:28:12 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/05 13:29:57 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (dest[i])
		i++;
	while (src[a])
	{
		dest[i + a] = src[a];
		a++;
	}
	dest[i + a] = '\0';
	return (dest);
}
