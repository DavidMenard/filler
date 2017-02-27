/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 07:26:23 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/26 08:24:02 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoin(char *dest, char deli, char *src)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (!(newstr = (char*)malloc(ft_strlen(dest) + ft_strlen(src) + 2)))
		return (NULL);
	while (*dest)
		newstr[i++] = *dest++;
	newstr[i++] = deli;
	while (*src)
		newstr[i++] = *src++;
	newstr[i] = '\0';
	return (newstr);
}
