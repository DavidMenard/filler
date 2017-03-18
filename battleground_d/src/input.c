/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:18:37 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:44:08 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void	ft_update_scores(t_data *data)
{
	data->p1_pieces = data->turns[data->turn]->p1_moves;
	data->p2_pieces = data->turns[data->turn]->p2_moves;
}

int		ft_input(t_data *data)
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
	else if ((key == KEY_DOWN || key == KEY_RIGHT)
	&& data->turn < data->turns_nbr - 1)
		data->turn++;
	else if ((key == KEY_UP || key == KEY_LEFT) && data->turn > 0)
		data->turn--;
	else if (key == 'e')
		data->turn = data->turns_nbr - 1;
	else if (key == 's')
		data->turn = 0;
	ft_update_scores(data);
	return (ret);
}
