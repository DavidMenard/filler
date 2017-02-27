/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_switchx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:04:49 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 15:14:23 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_switchx(va_list ap, t_conv *cd)
{
	if (cd->size == 'H')
		return (pcft_hhx(ap, cd));
	if (cd->size == 'h')
		return (pcft_hx(ap, cd));
	if (cd->size == 'l')
		return (pcft_lx(ap, cd));
	if (cd->size == 'L')
		return (pcft_llx(ap, cd));
	if (cd->size == 'j')
		return (pcft_jx(ap, cd));
	if (cd->size == 'z')
		return (pcft_zx(ap, cd));
	return (pcft_x(ap, cd));
}
