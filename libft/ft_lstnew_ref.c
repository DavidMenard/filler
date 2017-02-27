/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:21:53 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/14 12:25:48 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew_ref(void const *content, size_t content_size)
{
	t_list		*lp;

	if (!(lp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		lp->content = (void*)content;
		lp->content_size = content_size;
	}
	else
	{
		lp->content = NULL;
		lp->content_size = 0;
	}
	lp->next = NULL;
	return (lp);
}
