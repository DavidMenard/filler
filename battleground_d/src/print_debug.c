/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:07:33 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/02 18:52:02 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static void	sft_print_grid(char **grid)
{
	while (*grid)
	{
		ft_putendl(*grid);
		grid++;
	}
	ft_putl();
}

void		ft_debug_print_turns(t_data *data)
{
	int		i;
	t_turn	*turn;

	i = 0;
	while (i < data->turns_nbr)
	{
		turn = data->turns[i];
		sft_print_grid(turn->grid);
		i++;
	}
}
