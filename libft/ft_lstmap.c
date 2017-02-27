/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:26:10 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/09 16:51:09 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	stft_lstaddend(t_list *start, t_list *new)
{
	if (!start)
		return ;
	while (start->next)
		start = start->next;
	start->next = new;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!f)
		return (NULL);
	if (lst)
	{
		new = f(lst);
		if (!new)
			return (NULL);
		lst = lst->next;
	}
	else
		return (NULL);
	while (lst)
	{
		temp = f(lst);
		if (!temp)
			return (NULL);
		stft_lstaddend(new, temp);
		lst = lst->next;
	}
	return (new);
}
