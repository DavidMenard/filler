/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:54:04 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/05 17:57:42 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t wc)
{
	if (wc <= 0x7f)
		return (1);
	if (wc <= 0x7ff)
		return (2);
	if (wc <= 0xffff)
		return (3);
	if (wc <= 0x10ffff)
		return (4);
	return (0);
}
