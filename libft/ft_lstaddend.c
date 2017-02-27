/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:15:50 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/14 12:32:03 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*nav;

	nav = *alst;
	if (!nav)
	{
		*alst = new;
		return ;
	}
	while (nav->next)
		nav = nav->next;
	nav->next = new;
}
