/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/27 18:53:06 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"
#include <fcntl.h>

static void	sft_data_init(t_data *data)
{
	data->turns = NULL;
	data->turns_nbr = 0;
	data->p1_name = NULL;
	data->p2_name = NULL;
}

int main(void)
{
	t_data	data;

	ft_parser(&data);
	return (0);
}
