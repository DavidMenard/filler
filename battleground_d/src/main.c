/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 04:25:09 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"
#include <fcntl.h>

static void	sft_custome_colors(void)
{
	init_color(40, 1000, 454, 196); //p1 dynamic
	init_color(41, 1000, 536, 210); //p1 dynamic
	init_color(42, 1000, 590, 220); //p1 dynamic
	init_color(43, 492, 760, 824); //p2 dynamic
	init_color(44, 560, 816, 876); //p2 dynamic
	//init_color(45, 584, 820, 876); //p2 dynamic
	init_color(45, 700, 900, 1000); //p2 dynamic
	
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

	init_pair(14, 40, COLOR_BLACK);//p1 dynamic
	init_pair(15, 41, COLOR_BLACK);//p1 dynamic
	init_pair(16, 42, COLOR_BLACK);//p1 dynamic
	
	init_pair(17, 43, COLOR_BLACK);//p2 dynamic
	init_pair(18, 44, COLOR_BLACK);//p2 dynamic
	init_pair(19, 45, COLOR_BLACK);//p2 dynamic
}


static void	sft_standard_colors(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(11, COLOR_YELLOW, COLOR_BLACK);
	init_pair(12, COLOR_YELLOW, COLOR_BLACK);
	init_pair(13, COLOR_WHITE, COLOR_BLACK);

}

static void	sft_ncurses_init(void)
{
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	start_color();
	if (can_change_color())
		sft_custome_colors();
	else
		sft_standard_colors();
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
	data->p1_pieces = 0;
	data->p2_pieces = 0;
	data->frame = 0;
}

int			main(void)
{
	t_data	data;
	t_turn	*turn;

	sft_data_init(&data);
	sft_ncurses_init();
	ft_parser(&data);
	freopen("/dev/tty", "r", stdin);
	data.turn = data.turns_nbr - 1;
	ft_update_scores(&data);
	while (42)
	{
		ft_input(&data);
		turn = data.turns[data.turn];
		ft_update_display(&data, turn->grid, turn->p1_moves, turn->p2_moves);//
	}
	endwin();
	return (0);
}
