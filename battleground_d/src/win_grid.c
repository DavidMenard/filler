/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:13:01 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 04:30:18 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_print_line(int x, int y, char *str, WINDOW *win_grid, t_data *data)
{
	int	i;

	wmove(win_grid, y, x);
	i = 0;
	while (str[i])
	{
		wattron(win_grid, COLOR_PAIR(1));
		if (str[i] == '.')
		{
			waddch(win_grid, ' ');
			waddch(win_grid, ' ');
		}
		else if (str[i] == 'O' || str[i] == 'o')
		{
			if (str[i] == 'O')
				wattron(win_grid, COLOR_PAIR(14 + data->col_frame + i % 2));
			else
				wattron(win_grid, COLOR_PAIR(4));
			waddch(win_grid, '[');
			waddch(win_grid, ']');
		}
		else if (str[i] == 'X' || str[i] == 'x')
		{
			if (str[i] == 'X')
				wattron(win_grid, COLOR_PAIR(17 + data->col_frame + i % 2));
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
		i++;
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
		data->col_frame = (i % 2);
		sft_print_line(2, i + 1, grid[i], win_grid, data);
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
