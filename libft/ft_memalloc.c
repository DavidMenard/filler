/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:14:09 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/09 13:45:34 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (size < 1)
		return (NULL);
	temp = (char*)malloc(size);
	if (!temp)
		return (NULL);
	while (i < size)
		temp[i++] = '\0';
	return ((void*)temp);
}
