/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_chartab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:30:03 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/01 23:39:13 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_chartab(char **tab, int start, int end)
{
	char	*swap;

	if (!tab)
		return ;
	while (end > start)
	{
		swap = tab[start];
		tab[start++] = tab[end];
		tab[end--] = swap;
	}
}
