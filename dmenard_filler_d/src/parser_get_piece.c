/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:42:51 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/07 23:24:39 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_get_piece_size(t_data *data)
{
	char	*str;
	int		ret;

	str = NULL;
	if ((ret = get_next_line(0, &str)) && ret != -1)
	{
		if (ft_strncmp("Piece ", str, 6) ||
		ft_charcount(str, ' ') != 2 || ft_charcount(str, ':') != 1)
		{
			free(str);
			return (0);
		}
		data->py = ft_atoi(ft_strchr(str, ' ') + 1);
		data->px = ft_atoi(ft_strchr(ft_strchr(str, ' ') + 1, ' ') + 1);
	}
	else
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

int	ft_get_piece(t_data *data)
{
	char	*str;
	int		ret;
	int		i;
	char	**piece;

	ret = 0;
	if (!(piece = (char**)malloc(sizeof(char*) * data->py)))
		return (0);
	i = 0;
	while (i < data->py && (ret = get_next_line(0, &str) && ret != -1))
	{
		if (!ft_strexclu(str, "*.") || (int)ft_strlen(str) != data->px)
			return (0);
		piece[i++] = str;
	}
	if (i != data->py)
		return (0);
	data->piece = piece;
	return (1);
}
