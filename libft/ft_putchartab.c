/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchartab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 07:40:30 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/30 10:54:15 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchartab(char **tab, int start, int end)
{
	int i;

	i = start;
	while (i <= end)
	{
		if (tab[i])
			ft_putendl(tab[i++]);
	}
}
