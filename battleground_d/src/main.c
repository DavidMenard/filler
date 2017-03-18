/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:53:02 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_ncurses_init(void)
{
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	start_color();
	if (can_change_color())
		ft_custome_colors();
	else
		ft_standard_colors();
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
		ft_update_display(&data, turn->grid, turn->p1_moves, turn->p2_moves);
	}
	endwin();
	return (0);
}
