/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 08:28:24 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/06 13:40:18 by dmenard          ###   ########.fr       */
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

static int	sft_get_grid_size(t_data *data)
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

static int	sft_get_grid(t_data *data)
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
	while ((ret = get_next_line(0, &str)) && ret != -1 && i < data->gy - 1)
	{
		grid[i++] = ft_strdup(ft_strchr(str, ' ') + 1);
		free(str);
		str = NULL;
	}
	free(str);
	data->grid = grid;
	return (1);
}

int		ft_parser(t_data *data)
{
	if (!sft_getpnbr(data))
		return (0);
	if (!(sft_get_grid_size(data)) || !data->gx || !data->gy)
		return (0);
	if (!(sft_get_grid(data) || !data->grid))
		return (0);
//	if (!(sft_get_piece_size(data)) || !data->px || !data->py)
//		return (0);
//	ft_printf("%yx:%d\ny:%d\n", 2, data->px, data->py);//
	ft_print_grid(data);//
	return (1);
}
