/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:23:43 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/06 14:27:24 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charcount(char *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str++ == c)
			count++;
	}
	return (count);
}