/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:26:22 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void		sft_data_init(t_data *data)
{
	data->grid = NULL;
	data->vgrid = NULL;
	data->curr_control = 0;
	data->piece = NULL;
	data->gx = 0;
	data->gy = 0;
	data->px = 0;
	data->py = 0;
	data->center_piece_x = 0;
	data->center_piece_y = 0;
	data->pnbr = 0;
	data->moves = NULL;
	data->stage = 0;
}

static int	sft_get_turn(t_data *data)
{
	int pgx;
	int pgy;

	pgx = data->gx;
	pgy = data->gy;
	if (!(ft_get_grid_size(data)) || data->gx != pgx || data->gy != pgy)
		return (0);
	if (!(ft_get_grid_turn(data) || !data->grid))
		return (0);
	ft_del_piece(data);
	if (!(ft_get_piece_size(data)) || data->px < 1 || data->py < 1)
		return (0);
	if (!ft_get_piece(data) || !data->piece)
		return (0);
	return (1);
}

int			main(void)
{
	t_data data;

	sft_data_init(&data);
	if (!ft_parser(&data))
		return (-1);
	if (!(data.vgrid = ft_vgrid_init(data.gx, data.gy)))
		return (-1);
	ft_make_move(&data);
	while (sft_get_turn(&data))
	{
		ft_make_move(&data);
	}
	return (0);
}
