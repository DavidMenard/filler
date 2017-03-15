/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:26:29 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/15 08:57:14 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_grid(t_data *data)
{
	int	i;

	if (data)
	{
		i = 0;
		while (i < data->gy)
			ft_putendl_fd(data->grid[i++], 2);
	}
	ft_putchar_fd('\n', 2);
}

void	ft_print_moves(t_data *data)
{
	t_list	*nav;
	t_move	*move;

	nav = data->moves;
	while (nav)
	{
		move = (t_move*)nav->content;
		ft_printf("%yX:%d\nY:%d\nScore:%d\n",2,  move->x, move->y, move->score);
		nav = nav->next;
	}
}

void	ft_print_input(void)
{
	char	*str;
	int		ret;

	str = NULL;
	while ((ret = get_next_line(0, &str)) && ret != -1)
	{
		ft_putendl_fd(str, 2);
		free(str);
		str = NULL;
	}
	free(str);
}

void	ft_print_piece(t_data *data)
{
	int i;

	i = 0;
	while (i < data->py)
		ft_putendl_fd(data->piece[i++], 2);
	ft_printf("%ycenter_x:%d\ncenter_y%d\n", 2, data->center_piece_x, data->center_piece_y);///
	ft_putendl_fd("", 2);
}
