/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_blocking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:22:18 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/15 13:40:43 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	sft_check_proxy(t_data *data, int x, int y)
{
	int count;

	count = 0;
	count += ft_ishis(data, x + 1, y);
	count += ft_ishis(data, x - 1, y);
	count += ft_ishis(data, x, y + 1);
	count += ft_ishis(data, x, y - 1);
	return (count);
}

int	ft_get_blocking(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int count;
	
	count = 0;
	i = 0;
	while (i < data->py)
	{
		j = 0;
		while (j < data->px)
		{
			if (data->piece[i][j] == '*')
				count += sft_check_proxy(data, x + j, y + i);
			j++;
		}
		i++;
	}
	return (count);
}
