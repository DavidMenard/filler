/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:18:37 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 02:11:03 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void	ft_update_scores(t_data *data)
{
	data->p1_pieces = data->turns[data->turn]->p1_moves;
	data->p2_pieces = data->turns[data->turn]->p2_moves;
}

int	ft_input(t_data *data)
{
	int	key;
	int	ret;

	ret = 0;
	key = wgetch(data->win_grid);
	if (key == 'q')
	{
		endwin();
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_DOWN || key == KEY_RIGHT)
	{
		if (data->turn < data->turns_nbr - 1)
		{
			data->turn++;
			ret = 1;
			ft_update_scores(data);
		}
	}
	else if (key == KEY_UP || key == KEY_LEFT)
	{
		if (data->turn > 0)
		{
			data->turn--;
			ret = 1;
			ft_update_scores(data);
		}
	}
	return (ret);
}
