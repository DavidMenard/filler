/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:49:48 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/27 19:11:55 by dmenard          ###   ########.fr       */
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

void	ft_parser(t_data *data)
{
	sft_get_players(data);
	if (!data->p1_name || !data->p2_name)
		ft_error("Invalid input");
}
