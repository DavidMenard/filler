/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:29:43 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 16:43:56 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprepad(char *str, size_t n, char c)
{
	char	*newstr;
	size_t	i;
	size_t	size;
	size_t	sstr;

	sstr = ft_strlen(str);
	size = sstr > n ? sstr : n;
	if (!(newstr = (char*)malloc(size)))
		return (NULL);
	i = 0;
	while (i + sstr < n)
		newstr[i++] = c;
	ft_strcpy(newstr + i, str);
	return (newstr);
}
