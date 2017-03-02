/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/02 13:31:47 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"
#include <fcntl.h>

static void	sft_ncurses_init(void)
{
	setlocale(LC_ALL, "");
	freopen("/dev/tty", "r", stdin);
	initscr();
	raw();
	noecho();
	curs_set(0);
	start_color();
	init_color(30, 1000, 300, 0); //p1
	init_color(31, 0, 0, 1000); //p2
	init_color(32, 200, 200, 400);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, 30, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, 30);
	init_pair(5, 31, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, 31);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(9, COLOR_BLACK, 32);
//	init_pair(3, COLOR_WHITE, 30);
//	init_pair(4, COLOR_WHITE, 31);
//	init_pair(5, COLOR_BLACK, 32);
//	init_pair(6, COLOR_BLACK, 33);
}

static void	sft_data_init(t_data *data)
{
	data->turns = NULL;
	data->turn = 0;
	data->turns_nbr = 0;
	data->p1_name = NULL;
	data->p2_name = NULL;
	data->gridsize_x = 0;
	data->gridsize_y = 0;
	data->total_pieces = 0;
	data->p1_pieces = 0;
	data->p2_pieces = 0;
	data->p1_control = 0;
	data->p2_control = 0;
	data->neutral_control = 0;
}

int main(void)
{
	t_data	data;

	sft_data_init(&data);
	ft_parser(&data);
	data.total_pieces = data.gridsize_x * data.gridsize_y;
	sft_ncurses_init();
	ft_get_scores(&data);
	ft_create_win_grid(&data);
	keypad(data.win_grid, 1);
	ft_create_win_ban(&data);
	while (42)
	{
		ft_input(&data);
		ft_update_win_ban(&data);
		ft_update_win_grid(&data);
		wnoutrefresh(data.win_ban);
		wnoutrefresh(data.win_grid);
		doupdate();
	}
	endwin();
	return (0);
}
