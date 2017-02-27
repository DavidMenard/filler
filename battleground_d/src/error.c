/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:56:12 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/27 19:40:05 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

void	ft_error(char *errmsg)
{
	ft_printf("%ybattleground: error: %s\n", 2, errmsg);
	exit(EXIT_FAILURE);
}

void	*ft_smalloc(size_t n)
{
	void	*ret;

	if (!(ret = malloc(n)))
		ft_error("Out of memory");
	return (ret);
}
