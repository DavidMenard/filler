/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpostpad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:30:22 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 16:43:42 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpostpad(char *str, size_t n, char c)
{
	char	*newstr;
	size_t	i;
	size_t	size;
	size_t	sstr;

	sstr = ft_strlen(str);
	size = sstr > n ? sstr : n;
	if (!(newstr = (char*)malloc(size)))
		return (NULL);
	ft_strcpy(newstr, str);
	i = sstr;
	while (i < n)
		newstr[i++] = c;
	newstr[i] = '\0';
	return (newstr);
}
