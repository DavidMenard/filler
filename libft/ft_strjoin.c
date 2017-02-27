/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:16:16 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/24 11:19:05 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char*)malloc(len + 1);
	if (!newstr)
		return (NULL);
	ft_memset(newstr, '.', (size_t)len);
	newstr[len] = '\0';
	ft_strcpy(newstr, s1);
	newstr = ft_strcat(newstr, s2);
	return (newstr);
}
