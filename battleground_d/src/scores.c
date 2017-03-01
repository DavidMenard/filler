/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:03:11 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/01 18:34:56 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static int	sft_get_percentage(int p, int total)
{
	return (((float)p / (float)total) * 100);
}

void	ft_get_scores(t_data *data)
{
	t_turn	*turn;
	int		i;
	int		j;
	int		neut;
	int		stop;

	turn = data->turns[data->turn];
	stop = 0;
	i = 0;
	while (turn->grid[i] && !stop)
	{
		j = 0;
		while (turn->grid[i][j] && !stop)
		{
			if (turn->grid[i][j] == 'o')
			{
				data->p1_pieces++;
				stop = 1;
			}
			else if (turn->grid[i][j] == 'x')
			{
				data->p2_pieces++;
				stop = 1;
			}
			j++;
		}
		i++;
	}
	data->p1_control = sft_get_percentage(data->p1_pieces, data->total_pieces);
	data->p2_control = sft_get_percentage(data->p2_pieces, data->total_pieces);
	neut = data->total_pieces - data->p1_pieces - data->p2_pieces;
	data->neutral_control = sft_get_percentage(neut, data->total_pieces);
}
