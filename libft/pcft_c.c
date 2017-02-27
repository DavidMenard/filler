/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:26:24 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/08 16:21:37 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pcft_c(va_list ap, t_conv *cd)
{
	char	c;
	int		ret;
	int		pad;
	char	padc;

	c = (char)va_arg(ap, int);
	ret = 1;
	padc = ' ';
	if (cd->zero)
		padc = '0';
	if (cd->width_given)
	{
		pad = cd->width > ret ? cd->width - ret : 0;
		if (!cd->left_align)
			ft_putstrpad_fd("", pad, padc, cd->fd);
	}
	ft_putchar_fd(c, cd->fd);
	if (cd->width_given && cd->left_align)
		ft_putstrpad_fd("", pad, padc, cd->fd);
	if (cd->width_given)
		ret += pad;
	return (ret);
}
