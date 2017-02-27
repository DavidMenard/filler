/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:49:01 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/09 16:50:31 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*todel;
	t_list	*next;

	next = *alst;
	while (next)
	{
		todel = next;
		next = next->next;
		ft_lstdelone(&todel, del);
		free(todel);
	}
	*alst = NULL;
}
