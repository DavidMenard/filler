/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/07 19:46:41 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>


void	sft_data_init(t_data *data)
{
	data->grid = NULL;
	data->piece = NULL;
	data->gx = 0;
	data->gy = 0;
	data->px = 0;
	data->py = 0;
	data->pnbr = 0;
}

int main(void)
{
	t_data data;

	if (!ft_parser(&data))
		return (-1);
	write(1, "0 0\n", 4);
	return (0);
}
