/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:47:33 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/05 21:32:54 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	target;
	int				i;

	i = 0;
	target = (unsigned char)c;
	while (str[i])
		i++;
	while (i > -1)
	{
		if (((unsigned char*)str)[i] == target)
			return ((char*)(str + i));
		i--;
	}
	return (NULL);
}
