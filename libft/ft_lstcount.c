/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:34:05 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/19 21:35:19 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *head)
{
	int count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
