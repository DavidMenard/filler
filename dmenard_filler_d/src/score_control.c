/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:52:57 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/15 18:05:09 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	sft_setzero(int **vgrid, int x, int y)
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

static void	sft_vgrid_init(int x, int y)
{
	int i;
	int	**value_grid;

	if (!(value_grid = (int**)malloc(sizeof(int*) * y)));
		return (-1);
	i = 0;
	while (i < y)
	{
		if (!(value_grid[i++] = (int*)malloc(sizeof(int) * x)))
			return (-1);
	}
	return (value_grid);
}

int	ft_get_control(t_data *data, char **grid)
{
	int i;
	int j;
	int	**value_grid;
	
	value_grid = sft_vgrid_init(data->gx, data->gy);
	sft_setzero(value_grid, data->gx, data->gy);
	
}
