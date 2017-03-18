/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ban.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:27:54 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 15:36:16 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_put_name(t_data *data, int x, int player, int score)
{
	int		tx;
	char	*tmp;
	char	*name;

	if (player == 1)
		name = data->p1_name;
	else
		name = data->p2_name;
	tx = x - (ft_strlen(name) + 2) / 2;
	wmove(data->win_ban, BAN_HEIGHT / 2, tx);
	if (player == 1)
		wattron(data->win_ban, COLOR_PAIR(3));
	else
		wattron(data->win_ban, COLOR_PAIR(5));
	tmp = ft_itoa(data->p1_pieces);
	wprintw(data->win_ban, "[%s]", name);
	wmove(data->win_ban, BAN_HEIGHT / 2 + 1, x - ((ft_strlen(tmp) + 2) / 2));
	free(tmp);
	wprintw(data->win_ban, "(%dP)", score);
}

static void	sft_put_filler(t_data *data, int x)
{
	wattron(data->win_ban, COLOR_PAIR(7));
	wmove(data->win_ban, 1, x + 39);
	wprintw(data->win_ban, "FILLER");
}

static void	sft_put_banner(t_data *data, int x)
{
	wmove(data->win_ban, 1, x);
	wattron(data->win_ban, COLOR_PAIR(8 + data->frame % 2));
	wprintw(data->win_ban,
	" ____        _   _   _       ____                           _ ");
	wmove(data->win_ban, 2, x);
	wattron(data->win_ban, COLOR_PAIR(9 + data->frame % 2));
	wprintw(data->win_ban,
	"| __ )  __ _| |_| |_| | ___ / ___|_ __ ___  _   _ _ __   __| |");
	wmove(data->win_ban, 3, x);
	wattron(data->win_ban, COLOR_PAIR(10 + data->frame % 2));
	wprintw(data->win_ban,
	"|  _ \\ / _` | __| __| |/ _ \\ |  _| '__/ _ \\| | | | '_ \\ / _` |");
	wmove(data->win_ban, 4, x);
	wattron(data->win_ban, COLOR_PAIR(11 + data->frame % 2));
	wprintw(data->win_ban,
	"| |_) | (_| | |_| |_| |  __/ |_| | | | (_) | |_| | | | | (_| |");
	wmove(data->win_ban, 5, x);
	wattron(data->win_ban, COLOR_PAIR(12 + data->frame % 2));
	if (data->frame % 2)
		wprintw(data->win_ban,
	"(~__,/ \\__~_|\\__)\\~_|_|\\___)\\__~_|_|  \\_,,/ (_~,_|_| |,|\\__,~)");
	else
		wprintw(data->win_ban,
	"(,~,~/ \\~,,~|\\~,)\\,~|,|\\~,~)\\~~~,|~|  \\,~~/ (,~~,|~| |~|\\~~,~)");
	sft_put_filler(data, x);
}

void		ft_update_win_ban(t_data *data, int p1s, int p2s)
{
	werase(data->win_ban);
	wattron(data->win_ban, COLOR_PAIR(13));
	wmove(data->win_ban, 6, 0);
	whline(data->win_ban, '=', BAN_WIDTH);
	wattron(data->win_ban, COLOR_PAIR(11));
	wmove(data->win_ban, 6, 0);
	waddch(data->win_ban, '[');
	wmove(data->win_ban, 6, BAN_WIDTH - 1);
	waddch(data->win_ban, ']');
	sft_put_banner(data, 24);
	sft_put_name(data, 12, 1, p1s);
	sft_put_name(data, 97, 2, p2s);
}

void		ft_create_win_ban(t_data *data)
{
	data->win_ban = newwin(BAN_HEIGHT, BAN_WIDTH, 0, (COLS - BAN_WIDTH) / 2);
	if (COLS < BAN_WIDTH)
	{
		endwin();
		ft_error("Need a bigger Terminal");
	}
}
