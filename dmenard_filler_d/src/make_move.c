/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:16:00 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/12 18:18:54 by dmenard          ###   ########.fr       */
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
				else if(!ft_isfree(data, x + px, y + py))
					return (0);
			//	if (mychars > 1)
		//			return (0);
			}
			px++;
		}
		py++;
	}
	return (mychars == 1);
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
			if (sft_can_place(x, y, data))
			{
				if (!(new = (t_move*)malloc(sizeof(t_move))))
				{
					data->moves = NULL;//
					return ;
				}
				new->x = x;
				new->y = y;
				new->score = ft_get_score(data, x, y);
				ft_lstadd(&data->moves, ft_lstnew_ref(new, sizeof(t_move*)));
			}
			x++;
		}
		y++;
	}
}

static t_move	*sft_find_best_move(t_list *head)
{
	t_list *best;

	best = head;
	while (head)
	{
		if (((t_move*)head->content)->score > ((t_move*)best->content)->score)
			best = head;
		head = head->next;
	}
	return ((t_move*)best->content);
}

void	ft_make_move(t_data *data)
{
	t_move *best;

	sft_find_all_moves(data);
	if (data->moves)
	{
		best = sft_find_best_move(data->moves);
		ft_printf("%d %d\n", best->y, best->x);
	}
	else
		write(1, "0 0\n", 4);
}
