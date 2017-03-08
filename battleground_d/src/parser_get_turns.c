/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_turns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:37:39 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/08 07:28:46 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static t_turn	*sft_create_turn(int len, int lines)
{
	char	*str;
	int		ret;
	t_turn	*turn;
	int		i;

	turn = (t_turn*)ft_smalloc(sizeof(t_turn));
	turn->grid = (char**)ft_smalloc(sizeof(char*) * lines + 1);
	turn->grid[lines] = NULL;
	i = 0;
	while ((ret = get_next_line(0, &str)) && i < lines)
	{
		if (ret == -1)
			ft_error("Read error");
		turn->grid[i] = ft_strdup(ft_strchr(str, ' ') + 1);
		if (ft_strlen(turn->grid[i]) != (size_t)len)
			ft_error("grid line inconsistant");
		free(str);
		str = NULL;
		i++;
	}
	free(str);
	ft_putchar('>');//
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
	int		i;
	t_list	*head;

	str = NULL;
	i = 0;
	head = NULL;
	ft_putstr(C_GREEN);
	while ((ret = get_next_line(0, &str)))
	{
		if (ret == -1)
			ft_error("Read error");
		if (!ft_strncmp(str, "    ", 4))
			ft_lstadd(&head, ft_lstnew_ref(sft_create_turn(
			data->gridsize_x, data->gridsize_y), sizeof(t_turn)));
		free(str);
	}
	free(str);
	ft_putstr(C_RESET);
	sft_transfer_turns(data, head);
}
