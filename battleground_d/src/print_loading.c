/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_loading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:30:40 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/15 09:37:14 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void	ft_print_loading(char **grid)
{
	int i;

	while (*grid)
	{
		i = 0;
		while ((*grid)[i])
		{
			if ((*grid)[i] == 'O' || *grid[0] == 'o')
				ft_putstr(C_RED);
			else if ((*grid)[i] == 'X' || *grid[0] == 'x')
				ft_putstr(C_GREEN);
			else
				ft_putstr(C_RESET);
			i++;
		}
		grid++;
	}
}
