/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:28:29 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/09 16:50:49 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lp;

	if (!(lp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(lp->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(lp->content, content, content_size);
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
