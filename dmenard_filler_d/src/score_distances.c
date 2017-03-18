/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_distances.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:23:07 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:25:35 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_get_distance_en(t_data *data, int x, int y)
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

int	ft_get_distance_en_last(t_data *data, int x, int y)
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

int	ft_get_dis_wall(t_data *data, int x, int y)
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
