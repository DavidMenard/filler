/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:14:08 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/22 08:15:46 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		**sft_cpygrid(t_data *data, int x, int y)
{
	char	**newgrid;
	int		i;
	int		j;

	if (!(newgrid = (char**)malloc(sizeof(char*) * data->gy)))
		return (NULL);
	i = 0;
	while (i < data->gy)
	{
		if (!(newgrid[i] = ft_strdup(data->grid[i])))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < data->py)
	{
		j = -1;
		while (++j < data->px)
		{
			if (data->piece[i][j] == '*')
				newgrid[y + i][x + j] = data->pnbr == 1 ? 'o' : 'x';
		}
		i++;
	}
	return (newgrid);
}

static void		sft_del_cpygrid(t_data *data, char **cpygrid)
{
	int i;

	i = 0;
	while (i < data->gy)
		free(cpygrid[i++]);
	free(cpygrid);
}

static int		sft_center_free(t_data *data)
{
	int gx;
	int gy;

	gx = data->gx / 2;
	gy = data->gy / 2;
	if (ft_isfree(data, gx, gy) && ft_isfree(data, gx + 1, gy) &&
			ft_isfree(data, gx, gy + 1) && ft_isfree(data, gx + 1, gy + 1))
	{
		return (1);
	}
	return (0);
}

static void		sft_fill_score(t_data *data, int x, int y, t_score *s)
{
	s->block = ft_get_blocking(data, x, y);
	s->tgrid = sft_cpygrid(data, x, y);
	s->disen = ft_get_distance_en(
		data, x + data->center_piece_x, y + data->center_piece_y);
	s->diswall = ft_get_dis_wall(
		data, x + data->center_piece_x, y + data->center_piece_y);
	s->dislast = ft_get_distance_en_last(
		data, x + data->center_piece_x, y + data->center_piece_y);
	s->control = (ft_get_control(
		data, s->tgrid) - data->curr_control) / (data->gx * data->gy / 2);
	sft_del_cpygrid(data, s->tgrid);
}

int				ft_get_score(t_data *data, int x, int y)
{
	t_score s;

	sft_fill_score(data, x, y, &s);
	if (data->stage == 0)
	{
		if (!(s.block) && sft_center_free(data))
			return (-(s.diswall));
		else
			data->stage++;
	}
	if (!(s.block))
		return (s.dislast * 4 + s.disen);
	else
		return (s.control);
}
