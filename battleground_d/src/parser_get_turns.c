/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_turns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:37:39 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 17:53:08 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static int		sft_whoplayed(char **grid)
{
	int i;

	while (*grid)
	{
		i = 0;
		while ((*grid)[i])
		{
			if ((*grid)[i] == 'o')
				return (1);
			if ((*grid)[i] == 'x')
				return (2);
			i++;
		}
		grid++;
	}
	return (0);
}

static t_turn	*sft_create_turn(int len, int lines)
{
	char	*str;
	int		ret;
	t_turn	*turn;
	int		i;
	char	*tstr;

	turn = (t_turn*)ft_smalloc(sizeof(t_turn));
	turn->grid = (char**)ft_smalloc(sizeof(char*) * lines + 1);
	turn->grid[lines] = NULL;
	i = 0;
	while ((ret = get_next_line(0, &str)) && i < lines)
	{
		if (ret == -1 || !(tstr = ft_strchr(str, ' ')) ||
			ft_strlen(tstr + 1) != (size_t)len)
			ft_error("input error");
		turn->grid[i] = ft_strdup(tstr + 1);
		if (ft_strlen(turn->grid[i]) != (size_t)len)
			ft_error("grid line inconsistant");
		free(str);
		str = NULL;
		i++;
	}
	free(str);
	return (turn);
}

static void		sft_transfer_turns(t_data *data, t_list *head)
{
	t_list	*todel;
	int		i;

	data->turns_nbr = ft_lstcount(head);
	i = data->turns_nbr;
	data->turns = (t_turn**)ft_smalloc(sizeof(t_turn*) * i);
	i--;
	while (head)
	{
		todel = head;
		data->turns[i--] = (t_turn*)head->content;
		head = head->next;
		free(todel);
	}
}

void			ft_get_turns(t_data *data)
{
	char	*str;
	int		ret;
	t_list	*head;
	t_turn	*turn;

	str = NULL;
	head = NULL;
	while ((ret = get_next_line(0, &str)))
	{
		if (ret == -1)
			ft_error("Read error");
		if (!ft_strncmp(str, "    ", 4))
		{
			turn = sft_create_turn(data->gridsize_x, data->gridsize_y);
			data->p1_pieces += sft_whoplayed(turn->grid) == 1;
			data->p2_pieces += sft_whoplayed(turn->grid) == 2;
			turn->p1_moves = data->p1_pieces;
			turn->p2_moves = data->p2_pieces;
			ft_lstadd(&head, ft_lstnew_ref(turn, sizeof(t_turn)));
			ft_update_display(data, turn->grid, turn->p1_moves, turn->p2_moves);
		}
		free(str);
	}
	free(str);
	sft_transfer_turns(data, head);
}
