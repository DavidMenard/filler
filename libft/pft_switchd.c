/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_switchd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:05:44 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 14:05:27 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_switchd(va_list ap, t_conv *cd)
{
	if (cd->size == 'H')
		return (pcft_hhd(ap, cd));
	if (cd->size == 'h')
		return (pcft_hd(ap, cd));
	if (cd->size == 'l')
		return (pcft_ld(ap, cd));
	if (cd->size == 'L')
		return (pcft_lld(ap, cd));
	if (cd->size == 'j')
		return (pcft_jd(ap, cd));
	if (cd->size == 'z')
		return (pcft_zd(ap, cd));
	return (pcft_d(ap, cd));
}
