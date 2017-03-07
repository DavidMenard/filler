/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:40:40 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/07 19:42:12 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_get_grid_size(t_data *data)
{
	char	*str;
	char	*temp;
	int		ret;

	str = NULL;
	while ((ret = get_next_line(0, &str)))
	{
		if (ret == -1)
		{
			ft_putendl_fd("Read error", 2);
			return (0);
		}
		if (!ft_strncmp(str, "Plateau ", 8))
		{
			temp = ft_strchr(str, ' ') + 1;
			data->gy = ft_atoi(temp);
			data->gx = ft_atoi(ft_strchr(temp, ' '));
			break ;
		}
		free(str);
		str = NULL;
	}
	free(str);
	return (1);
}

int	ft_get_grid(t_data *data)
{
	char	*str;
	int		ret;
	char	**grid;
	int		i;

	if (!(grid = (char**)malloc(sizeof(char*) * data->gy)))
		return (0);
	str = NULL;
	ret = get_next_line(0, &str);
	if (!ret || ret == -1 || strncmp(str, "    0", 5))
		return (0);
	free(str);
	i = 0;
	while (i < data->gy && (ret = get_next_line(0, &str)) && ret != -1)
	{
		grid[i++] = ft_strdup(ft_strchr(str, ' ') + 1);
		free(str);
		str = NULL;
	}
	free(str);
	data->grid = grid;
	return (1);
}
