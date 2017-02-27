/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:23:47 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/04 20:25:33 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrend(char *str, char c)
{
	int i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		--i;
	}
	return (NULL);
}
