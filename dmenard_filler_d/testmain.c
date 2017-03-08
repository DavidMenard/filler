/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:13:13 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/08 01:44:25 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main(void)
{
	t_data data;

	data.moves = NULL;
	data.pnbr = 1;

	ft_get_grid_size(&data);
	ft_get_grid(&data);
	ft_get_piece_size(&data);
	ft_get_piece(&data);

	ft_print_grid(&data);
	ft_print_piece(&data);
	ft_make_move(&data);
	return (0);
}
