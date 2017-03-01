/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:18:37 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/01 15:01:59 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void	ft_input(t_data *data)
{
	int	key;

	key = wgetch(data->win_grid);
	if (key == 'q')
	{
		endwin();
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_DOWN || key == KEY_RIGHT)
	{
		if (data->turn < data->turns_nbr - 1)
			data->turn++;
	}
	else if (key == KEY_UP || key == KEY_LEFT)
	{
		if (data->turn > 0)
			data->turn--;
	}
}
