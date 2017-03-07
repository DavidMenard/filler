/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexclu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:42:38 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/07 19:54:52 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return true if all the characters is the 1st str are also in the 2nd str.
*/

#include "libft.h"

int	ft_strexclu(const char *str, const char *ref)
{
	size_t	i;
	size_t	j;
	int		in;

	i = 0;
	while (str[i])
	{
		j = 0;
		in = 0;
		while (ref[j])
		{
			if (str[i] == ref[j])
				in = 1;
			j++;
		}
		if (!in)
			return (0);
		i++;
	}
	return (1);
}
