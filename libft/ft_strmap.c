/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:48:17 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/07 15:47:16 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	newstr = (char*)malloc(ft_strlen(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
