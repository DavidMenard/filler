/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 01:06:02 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 01:46:55 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void	ft_update_display(t_data *data, char **grid, int p1s, int p2s)
{
	data->frame++;
	if (data->frame > 1024)
		data->frame = 0;
	ft_update_win_ban(data, p1s, p2s);
	ft_update_win_grid(data, grid);
	wnoutrefresh(data->win_ban);
	wnoutrefresh(data->win_grid);
	doupdate();
}
