/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:52:57 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:37:30 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_setzero(int **vgrid, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			vgrid[i][j++] = 0;
		i++;
	}
}

int			**ft_vgrid_init(int x, int y)
{
	int i;
	int	**value_grid;

	if (!(value_grid = (int**)malloc(sizeof(int*) * y)))
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (!(value_grid[i++] = (int*)malloc(sizeof(int) * x)))
			return (NULL);
	}
	return (value_grid);
}

static long	sft_get_total(t_data *data, int **vgrid)
{
	int		i;
	int		j;
	long	total;

	total = 0;
	i = 0;
	while (i < data->gy)
	{
		j = 0;
		while (j < data->gx)
		{
			total += vgrid[i][j];
			j++;
		}
		i++;
	}
	return (total);
}

long		ft_get_control(t_data *data, char **grid)
{
	ft_setzero(data->vgrid, data->gx, data->gy);
	ft_vgrid_fill_left(data, data->vgrid, grid);
	ft_vgrid_fill_right(data, data->vgrid, grid);
	ft_vgrid_fill_top(data, data->vgrid, grid);
	ft_vgrid_fill_bot(data, data->vgrid, grid);
	return (sft_get_total(data, data->vgrid));
}
