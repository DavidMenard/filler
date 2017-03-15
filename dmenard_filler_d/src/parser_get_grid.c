/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:40:40 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/15 11:54:14 by dmenard          ###   ########.fr       */
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
		if (ft_strlen(grid[i - 1]) != (size_t)data->gx)
			return (0);
		free(str);
		str = NULL;
	}
	free(str);
	data->grid = grid;
	return (1);
}

static void	sft_grid_compare(char **new, char **old, int gx, int gy, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < gy)
	{
		j = 0;
		while (j < gx)
		{
			if (data->pnbr == 1 && new[i][j] == 'X' && old[i][j] != 'X')
				new[i][j] = 'x';
			if (data->pnbr == 2 && new[i][j] == 'O' && old[i][j] != 'O')
				new[i][j] = 'o';
			j++;
		}
		i++;
	}
}

int	ft_get_grid_turn(t_data *data)
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
		if (ft_strlen(grid[i - 1]) != (size_t)data->gx)
			return (0);
		free(str);
		str = NULL;
	}
	free(str);
	sft_grid_compare(grid, data->grid, data->gx, data->gy, data);
	ft_del_grid(data);
	data->grid = grid;
	return (1);
}
