/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_turn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:10:52 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/08 00:50:09 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_del_grid(t_data *data)
{
	int i;

	i = 0;
	while (i < data->gy)
		free(data->grid[i++]);
	free(data->grid);
	data->grid = NULL;
}

void	ft_del_piece(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->py)
		free(data->piece[i++]);
	free(data->piece);
	data->piece = NULL;
}

void	ft_del_moves(t_data *data)
{
	t_list	*nav;
	t_list	*todel;

	nav = data->moves;
	while (nav)
	{
		todel = nav;
		nav = nav->next;
		free(todel->content);
		free(todel);
	}
	data->moves = NULL;
}
