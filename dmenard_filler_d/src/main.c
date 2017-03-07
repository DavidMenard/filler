/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/08 00:14:47 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	sft_data_init(t_data *data)
{
	data->grid = NULL;
	data->piece = NULL;
	data->gx = 0;
	data->gy = 0;
	data->px = 0;
	data->py = 0;
	data->pnbr = 0;
	data->moves = NULL;
}

static int	sft_get_turn(t_data *data)
{
	int pgx;
	int pgy;

	pgx = data->gx;
	pgy = data->gy;
	ft_del_grid(data);
	if (!(ft_get_grid_size(data)) || data->gx != pgx || data->gy != pgy)
		return (0);
	if (!(ft_get_grid(data) || !data->grid))
		return (0);
	ft_del_piece(data);
	if (!(ft_get_piece_size(data)) || data->px < 1 || data->py < 1)
		return (0);
	if (!ft_get_piece(data) || !data->piece)
		return (0);
	return (1);
}

int main(void)
{
	t_data data;

	sft_data_init(&data);
	if (!ft_parser(&data))
		return (-1);
	ft_make_move(&data);
	while (sft_get_turn(&data))
		ft_make_move(&data);
	return (0);
}
