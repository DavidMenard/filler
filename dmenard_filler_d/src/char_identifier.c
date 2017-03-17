/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:41:50 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 04:59:28 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_ismine(t_data *data, int x, int y)
{
	char c;

	if (x >= data->gx || y >= data->gy || x < 0 || y < 0)
		return (0);
	c = data->grid[y][x];
	if (data->pnbr == 1)
	{
		if (c == 'O' || c == 'o')
			return (1);
		return (0);
	}
	else
	{
		if (c == 'X' || c == 'x')
			return (1);
		return (0);
	}
}

int		ft_ishis(t_data *data, int x, int y)
{
	char c;

	if (x >= data->gx || y >= data->gy || x < 0 || y < 0)
		return (0);
	c = data->grid[y][x];
	if (data->pnbr == 1)
	{
		if (c == 'X' || c == 'x')
			return (1);
		return (0);
	}
	else
	{
		if (c == 'O' || c == 'o')
			return (1);
		return (0);
	}
}

int		ft_isfree(t_data *data, int x, int y)
{
	if (x >= data->gx || y >= data->gy || x < 0 || y < 0)
		return (0);
	if (data->grid[y][x] == '.')
		return (1);
	return(0);
}

int		ft_charplayer(char c)
{
	if (c == 'O' || c == 'o')
		return (1);
	if (c == 'X' || c == 'x')
		return (2);
	return (0);
}
