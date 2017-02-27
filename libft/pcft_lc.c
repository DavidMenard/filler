/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_lc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:51:38 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 10:28:01 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int		pcft_lc(va_list ap, t_conv *cd)
{
	wchar_t	c;
	int		ret;
	int		pad;

	c = (wchar_t)va_arg(ap, wint_t);
	ret = ft_wcharlen(c);
	if (cd->width_given)
	{
		pad = cd->width > ret ? cd->width - ret : 0;
		if (!cd->left_align)
			ft_putstrpad_fd("", pad, ' ', cd->fd);
	}
	ft_putwchar_fd(c, cd->fd);
	if (cd->width_given && cd->left_align)
		ft_putstrpad_fd("", pad, ' ', cd->fd);
	if (cd->width_given)
		ret += pad;
	return (ret);
}
