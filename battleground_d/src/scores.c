/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:03:11 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 01:11:34 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void		ft_get_scores_back(t_data *data)
{
	t_turn	*turn;
	int		i;
	int		j;
	int		stop;

	turn = data->turns[data->turn];
	stop = 0;
	i = 0;
	while (turn->grid[i] && !stop)
	{
		j = 0;
		while (turn->grid[i][j] && !stop)
		{
			if (turn->grid[i][j] == 'o')
			{
				data->p1_pieces--;
				stop = 1;
			}
			else if (turn->grid[i][j] == 'x')
			{
				data->p2_pieces--;
				stop = 1;
			}
			j++;
		}
		i++;
	}
}

void		ft_get_scores(t_data *data)
{
	t_turn	*turn;
	int		i;
	int		j;
	int		stop;

	turn = data->turns[data->turn];
	stop = 0;
	i = 0;
	while (turn->grid[i] && !stop)
	{
		j = 0;
		while (turn->grid[i][j] && !stop)
		{
			if (turn->grid[i][j] == 'o')
			{
				data->p1_pieces++;
				stop = 1;
			}
			else if (turn->grid[i][j] == 'x')
			{
				data->p2_pieces++;
				stop = 1;
			}
			j++;
		}
		i++;
	}
}
