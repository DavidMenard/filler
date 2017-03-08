/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/08 09:08:43 by dmenard          ###   ########.fr       */
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
	init_color(30, 1000, 454, 196); //p1
	init_color(31, 492, 760, 824); //p2
	init_color(32, 600, 200, 50); //FLAMES !
	init_color(33, 700, 250, 100); //FLAMES !
	init_color(34, 800, 300, 150); //FLAMES !
	init_color(35, 1000, 400, 200); //FLAMES !
	init_color(36, 900, 700, 200); //FLAMES !
	init_color(37, 1000, 1000, 600); //FLAMES !
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, 30, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, 30);
	init_pair(5, 31, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, 31);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, 32, COLOR_BLACK);
	init_pair(9, 33, COLOR_BLACK);
	init_pair(10, 34, COLOR_BLACK);
	init_pair(11, 35, COLOR_BLACK);
	init_pair(12, 36, COLOR_BLACK);
	init_pair(13, 37, COLOR_BLACK);
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
	data->frame = 0;
}

int			main(void)
{
	t_data	data;

	sft_data_init(&data);
	ft_parser(&data);
	data.total_pieces = data.gridsize_x * data.gridsize_y;
	sft_ncurses_init();
	ft_get_scores(&data);
	ft_create_win_grid(&data);
	keypad(data.win_grid, 1);
	nodelay(data.win_grid, 1);//
	ft_create_win_ban(&data);
	while (42)
	{
		ft_input(&data);
		data.frame++;
		if (data.frame > 1024)
			data.frame = 0;
		ft_update_win_ban(&data);
		ft_update_win_grid(&data);
		wnoutrefresh(data.win_ban);
		wnoutrefresh(data.win_grid);
		doupdate();
	}
	endwin();
	return (0);
}
