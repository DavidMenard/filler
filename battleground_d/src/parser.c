/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:49:48 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/01 13:04:17 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static char	*sft_extract_name(char *str)
{
	char	*front;
	int		i;

	front = ft_strchrend(str, '/');
	if (!front)
		front = str;
	i = 0;
	while (front[i] && front[i] != '.')
		i++;
	return (ft_strsub(front, 1, i - 1));
}

static void	sft_get_players(t_data *data)
{
	int		ret;
	char	*str;

	str = NULL;
	while ((ret = get_next_line(0, &str)) && !data->p1_name)
	{
		if (ret == -1)
			ft_error("Read error");
		if (ft_strstr(str, "$$$ exec p1 : ["))
			data->p1_name = sft_extract_name(str);
		free(str);
	}
	while ((ret = get_next_line(0, &str)) && !data->p2_name)
	{
		if (ret == -1)
			ft_error("Read error");
		if (ft_strstr(str, "$$$ exec p2 : ["))
			data->p2_name = sft_extract_name(str);
		free(str);
	}
	free(str);
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

void	ft_parser(t_data *data)
{
	sft_get_players(data);
	if (!data->p1_name || !data->p2_name)
		ft_error("Invalid input");
	sft_get_grid_size(data);
	if (!data->gridsize_x || !data->gridsize_y)
		ft_error("invalid grid size");
	ft_get_turns(data);
	if (!data->turns)
		ft_error("No turns found");
}
