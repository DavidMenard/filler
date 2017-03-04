/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 08:28:24 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/04 08:48:44 by dmenard          ###   ########.fr       */
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
	free (str);
	return (1);
}

static void	sft_get_grid_size(t_data *data)
{
	char	*str;
	char	*temp;
	int		ret;

	str = NULL;
	while ((ret = get_next_line(0, &str)))
	{
		if (ret == -1)
			ft_error("Read error");
		if (!ft_strncmp(str, "Plateau ", 8))
		{
			temp = ft_strchr(str, ' ') + 1;
			data->gridsize_y = ft_atoi(temp);
			data->gridsize_x = ft_atoi(ft_strchr(temp, ' '));
			break ;
		}
		free(str);
		str = NULL;
	}
	free(str);
}

int		ft_parser(t_data *data)
{
	if (!sft_getpnbr(data))
		return (0);
	if (!(sft_get_grid(data)) || !data->gx || !data->gy)
		return (0);
	return (1);
}
