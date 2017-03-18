/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_control_extras.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:54:22 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:09:53 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_vgrid_fill_left(t_data *data, int **vgrid, char **grid)
{
	int i;
	int j;
	int value;
	int pp;

	i = 0;
	while (i < data->gy)
	{
		j = 0;
		value = 0;
		while (j < data->gx)
		{
			if ((pp = ft_charplayer(grid[i][j])))
				value = pp == data->pnbr ? data->gx : data->gx * -1;
			else if (value)
				value += value > 0 ? -1 : 1;
			vgrid[i][j++] += value;
		}
		i++;
	}
}

void	ft_vgrid_fill_right(t_data *data, int **vgrid, char **grid)
{
	int i;
	int j;
	int value;
	int pp;

	i = 0;
	while (i < data->gy)
	{
		j = data->gx;
		value = 0;
		while (j >= 0)
		{
			if ((pp = ft_charplayer(grid[i][j])))
				value = pp == data->pnbr ? data->gx : data->gx * -1;
			else if (value)
				value += value > 0 ? -1 : 1;
			vgrid[i][j--] += value;
		}
		i++;
	}
}

void	ft_vgrid_fill_top(t_data *data, int **vgrid, char **grid)
{
	int i;
	int j;
	int value;
	int pp;

	i = 0;
	while (i < data->gx)
	{
		j = 0;
		value = 0;
		while (j < data->gy)
		{
			if ((pp = ft_charplayer(grid[j][i])))
				value = pp == data->pnbr ? data->gx : data->gx * -1;
			else if (value)
				value += value > 0 ? -1 : 1;
			vgrid[j++][i] += value;
		}
		i++;
	}
}

void	ft_vgrid_fill_bot(t_data *data, int **vgrid, char **grid)
{
	int i;
	int j;
	int value;
	int pp;

	i = 0;
	while (i < data->gx)
	{
		j = data->gy - 1;
		value = 0;
		while (j >= 0)
		{
			if ((pp = ft_charplayer(grid[j][i])))
				value = pp == data->pnbr ? data->gx : data->gx * -1;
			else if (value)
				value += value > 0 ? -1 : 1;
			vgrid[j--][i] += value;
		}
		i++;
	}
}
