/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:16:00 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/08 00:49:47 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	sft_can_place(int x, int y, t_data *data)
{
	int		mychars;
	int		px;
	int		py;

	mychars = 0;
	py = 0;
	if (data->px + x > data->gx || data->py + y > data->gy)
		return (0);
	while (py < data->py)
	{
		px = 0;
		while (px < data->px)
		{
			if (data->piece[py][px] == '*')
			{
				if (ft_ishis(data, x + px, y + py))
					return (0);
				if (ft_ismine(data, x + px, y + py))
					mychars++;
				else if(!ft_isfree(data, x + py, y + py))
					return (0);
				if (mychars > 1)
					return (0);
			}
			px++;
		}
		py++;
	}
	return (mychars == 1 ? 1 : 0);
}

static void	sft_find_all_moves(t_data *data)
{
	int		y;
	int		x;
	t_move	*new;

	y = 0;
	while (y < data->gy)
	{
		x = 0;
		while (x < data->gx)
		{
			if (sft_can_place(y, x, data))
			{
				if (!(new = (t_move*)malloc(sizeof(t_move))))
				{
					data->moves = NULL;//
					return ;
				}
				new->x = x;
				new->y = y;
				new->score = 0;
				ft_lstadd(&data->moves, ft_lstnew_ref(new, sizeof(t_move*)));
			}
			x++;
		}
		y++;
	}
}

void	ft_make_move(t_data *data)
{
	sft_find_all_moves(data);
	ft_print_piece(data);//
	if (data->moves)
		ft_printf("%d %d\n", ((t_move*)data->moves->content)->x, ((t_move*)data->moves->content)->y);
	else
		write(1, "0 0\n", 4);
	ft_del_moves(data);
}
