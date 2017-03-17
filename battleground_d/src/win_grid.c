/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:13:01 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 01:46:21 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_print_line(int x, int y, char *str, WINDOW *win_grid)
{
	wmove(win_grid, y, x);
	while (*str)
	{
		wattron(win_grid, COLOR_PAIR(1));
		if (*str == '.')
		{
			waddch(win_grid, ' ');
			waddch(win_grid, ' ');
		}
		else if (*str == 'O' || *str == 'o')
		{
			if (*str == 'O')
				wattron(win_grid, COLOR_PAIR(3));
			else
				wattron(win_grid, COLOR_PAIR(4));
			waddch(win_grid, '[');
			waddch(win_grid, ']');
		}
		else if (*str == 'X' || *str == 'x')
		{
			if (*str == 'X')
				wattron(win_grid, COLOR_PAIR(5));
			else
				wattron(win_grid, COLOR_PAIR(6));
			waddch(win_grid, '[');
			waddch(win_grid, ']');
		}
		else
		{
			waddch(win_grid, *str);
			waddch(win_grid, *str);
		}
		str++;
	}
}

void	ft_update_win_grid(t_data *data, char **grid)
{
	WINDOW	*win_grid;
	int		i;

	win_grid = data->win_grid;
	wattron(win_grid, COLOR_PAIR(7));
	wborder(win_grid, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
	ACS_DIAMOND, ACS_DIAMOND, ACS_DIAMOND, ACS_DIAMOND);
	wattron(win_grid, COLOR_PAIR(1));
	i = 0;
	while (grid[i])
	{
		sft_print_line(2, i + 1, grid[i], win_grid);
		i++;
	}
}

void	ft_create_win_grid(t_data *data)
{
	if (COLS < data->gridsize_x * 2 + 4)
	{
		endwin();
		ft_error("Need bigger terminal");
	}
	data->win_grid = newwin(data->gridsize_y + 2, data->gridsize_x * 2 + 4, BAN_HEIGHT, (COLS - (data->gridsize_x * 2)) / 2);
}
