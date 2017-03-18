/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:13:01 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 15:19:40 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_put_square(WINDOW *win_grid, char c, t_data *data, int i)
{
	int	col;

	if (ft_isupper(c))
	{
		col = c == 'O' ? 14 : 17;
		wattron(win_grid, COLOR_PAIR(col + data->col_frame + i % 2));
	}
	else
	{
		col = c == 'o' ? 4 : 6;
		wattron(win_grid, COLOR_PAIR(col));
	}
	waddstr(win_grid, "[]");
}

static void	sft_print_line(int y, char *str, WINDOW *win_grid, t_data *data)
{
	int	i;
	int	x;

	x = 2;
	wmove(win_grid, y, x);
	i = 0;
	while (str[i])
	{
		wattron(win_grid, COLOR_PAIR(1));
		if (str[i] == '.')
		{
			waddstr(win_grid, "  ");
		}
		else if (str[i] == 'O' || str[i] == 'o' ||
			str[i] == 'X' || str[i] == 'x')
			sft_put_square(win_grid, str[i], data, i);
		else
		{
			waddch(win_grid, *str);
			waddch(win_grid, *str);
		}
		i++;
	}
}

void		ft_update_win_grid(t_data *data, char **grid)
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
		sft_print_line(i + 1, grid[i], win_grid, data);
		i++;
	}
}

void		ft_create_win_grid(t_data *data)
{
	int height;
	int	len;
	int	x_pos;

	if (COLS < data->gridsize_x * 2 + 4)
	{
		endwin();
		ft_error("Need bigger terminal");
	}
	height = data->gridsize_y + 2;
	len = data->gridsize_x * 2 + 4;
	x_pos = (COLS - (data->gridsize_x * 2)) / 2;
	data->win_grid = newwin(height, len, BAN_HEIGHT, x_pos);
}
