/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_switchd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:05:44 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 15:36:48 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_switchu(va_list ap, t_conv *cd)
{
	if (cd->size == 'H')
		return (pcft_hhu(ap, cd));
	if (cd->size == 'h')
		return (pcft_hu(ap, cd));
	if (cd->size == 'l')
		return (pcft_lu(ap, cd));
	if (cd->size == 'L')
		return (pcft_llu(ap, cd));
	if (cd->size == 'j')
		return (pcft_ju(ap, cd));
	if (cd->size == 'z')
		return (pcft_zu(ap, cd));
	return (pcft_u(ap, cd));
}
