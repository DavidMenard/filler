/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:19:28 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/15 09:13:04 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	sft_get_distance_en(t_data *data, int x, int y)
{
	int	diff;
	int	tdiff;
	int	ty;
	int	tx;

	ty = 0;
	diff = INT_MAX;
	while (ty < data->gy)
	{
		tx = 0;
		while (tx < data->gx)
		{
			if (ft_ishis(data, tx, ty))
			{
				tdiff = ft_abs(ty - y) + ft_abs(tx - x);
				if (tdiff < diff)
					diff = tdiff;
			}
			tx++;
		}
		ty++;
	}
	return (-diff);
}

static int	sft_get_distance_en_last(t_data *data, int x, int y)
{
	int	diff;
	int	tdiff;
	int	ty;
	int	tx;

	ty = 0;
	diff = INT_MAX;
	while (ty < data->gy)
	{
		tx = 0;
		while (tx < data->gx)
		{
			if (ft_ishis(data, tx, ty) && !ft_isupper(data->grid[ty][tx]))
			{
				tdiff = ft_abs(ty - y) + ft_abs(tx - x);
				if (tdiff < diff)
					diff = tdiff;
			}
			tx++;
		}
		ty++;
	}
	return (-diff);
}

static int	sft_get_dis_wall(t_data *data, int x, int y)
{
	int dx;
	int dy;

	if (x > data->gx / 2)
		dx = data->gx - x;
	else
		dx = x;
	if (y > data->gy / 2)
		dy = data->gy - y;
	else
		dy = y;
	return (-dy - dx);
}

int		ft_get_score(t_data *data, int x, int y)
{
	int	disen;
	int	diswall;
	int	dislast;

	disen = sft_get_distance_en(data, x + data->center_piece_x, y + data->center_piece_y);
	diswall = sft_get_dis_wall(data, x, y);
	dislast = sft_get_distance_en_last(data, x + data->center_piece_x, y + data->center_piece_y);
	
	return (disen + dislast * 2);
}
