/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:42:51 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/12 17:24:47 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	sft_get_piece_center_x(char **piece, t_data *data)
{
	int	low;
	int	high;
	int	i;
	int	j;

	i = 0;
	low = INT_MAX;
	high = 0;
	while (i < data->py)
	{
		j = 0;
		while (j < data->px)
		{
			if (piece[i][j] != '.')
			{
				if (low > j)
					low = j;
				if (high < j)
					high = j;
			}
			j++;
		}
		i++;
	}
	return (low + (high - low) / 2);
}

static int	sft_get_piece_center_y(char **piece, t_data *data)
{
	int	low;
	int	high;
	int	i;
	int	j;

	i = 0;
	low = INT_MAX;
	high = 0;
	while (i < data->py)
	{
		j = 0;
		while (j < data->px)
		{
			if (piece[i][j] != '.')
			{
				if (low > i)
					low = i;
				if (high < i)
					high = i;
			}
			j++;
		}
		i++;
	}
	return (low + (high - low) / 2);
}

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
	data->center_piece_x = sft_get_piece_center_x(piece, data);
	data->center_piece_y = sft_get_piece_center_y(piece, data);
	data->piece = piece;
	return (1);
}
