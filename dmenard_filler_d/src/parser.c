/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 08:28:24 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 14:29:36 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	sft_getpnbr(t_data *data)
{
	char	*str;
	char	*tstr;
	int		ret;

	if (!(ret = get_next_line(0, &str)) || ret == -1)
	{
		ft_putendl_fd("Read error", 2);
		return (0);
	}
	if (strncmp(str, "$$$ exec p", 10))
	{
		ft_putendl_fd("Invalid line", 2);
		return (0);
	}
	tstr = ft_strchr(str, 'p') + 1;
	if ((*tstr != '1' && *tstr != '2') || *(tstr + 1) != ' ')
	{
		ft_putendl_fd("Invalid line", 2);
		return (0);
	}
	data->pnbr = ft_atoi(tstr);
	free(str);
	return (1);
}

int			ft_parser(t_data *data)
{
	if (!sft_getpnbr(data))
		return (0);
	if (!(ft_get_grid_size(data)) || data->gx < 1 || data->gy < 1)
		return (0);
	if (!(ft_get_grid(data) || !data->grid))
		return (0);
	if (!(ft_get_piece_size(data)) || data->px < 1 || data->py < 1)
		return (0);
	if (!ft_get_piece(data) || !data->piece)
		return (0);
	return (1);
}
