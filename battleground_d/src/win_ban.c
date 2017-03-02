/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ban.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:13:16 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/02 19:40:39 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_put_name(char *name, t_data *data, int x, int player)
{
	WINDOW	*win_ban;
	int		tx;
	char	*tmp;

	win_ban = data->win_ban;
	tx = x - (ft_strlen(name) + 2) / 2;
	wmove(win_ban, BAN_HEIGHT / 2, tx);
	if (player == 1)
		wattron(win_ban, COLOR_PAIR(3));
	else
		wattron(win_ban, COLOR_PAIR(5));
	tmp = ft_itoa(data->p1_pieces);
	wprintw(win_ban, "[%s]", name);
	wmove(win_ban, BAN_HEIGHT / 2 + 1, x - ((ft_strlen(tmp) + 2) / 2));
	free(tmp);
	if (player == 1)
		wprintw(win_ban, "(%dP)", data->p1_pieces);
	else
		wprintw(win_ban, "(%dP)", data->p2_pieces);
}

static void	sft_put_banner(t_data *data, int x)
{
	WINDOW	*win_ban;
	
	win_ban = data->win_ban;
	wattron(win_ban, COLOR_PAIR(8));
	wmove(win_ban, 1, x);
	wprintw(win_ban, " ____        _   _   _       ____                           _ ");
	wmove(win_ban, 2, x);
	wprintw(win_ban, "| __ )  __ _| |_| |_| | ___ / ___|_ __ ___  _   _ _ __   __| |");
	wmove(win_ban, 3, x);
	wprintw(win_ban, "|  _ \\ / _` | __| __| |/ _ \\ |  _| '__/ _ \\| | | | '_ \\ / _` |");
	wmove(win_ban, 4, x);
	wprintw(win_ban, "| |_) | (_| | |_| |_| |  __/ |_| | | | (_) | |_| | | | | (_| |");
	wmove(win_ban, 5, x);
	wprintw(win_ban, "|____/ \\__,_|\\__|\\__|_|\\___|\\____|_|  \\___/ \\__,_|_| |_|\\__,_|");
	wattron(win_ban, COLOR_PAIR(7));
	wmove(win_ban, 1, x + 37);
	wprintw(win_ban, "FILLER");
}

void	ft_update_win_ban(t_data *data)
{
	WINDOW	*win_ban;
	
	win_ban = data->win_ban;
	werase(win_ban);
	wattron(win_ban, COLOR_PAIR(8));
	wmove(win_ban, 6, 0);
	whline(win_ban, '=', BAN_WIDTH);
	sft_put_banner(data, 24);
	sft_put_name(data->p1_name, data, 12, 1);
	sft_put_name(data->p2_name, data, 97, 2);
}
void	ft_create_win_ban(t_data *data)
{
	WINDOW	*win_ban;

	data->win_ban = newwin(BAN_HEIGHT, BAN_WIDTH, 0, (COLS - BAN_WIDTH) / 2);
	if (COLS < BAN_WIDTH)
	{
		endwin();
		ft_error("Need a bigger Terminal");
	}
	win_ban = data->win_ban;
	ft_update_win_ban(data);
	wrefresh(win_ban);
}
