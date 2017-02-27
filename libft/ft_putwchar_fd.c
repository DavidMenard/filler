/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 10:22:13 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 10:28:29 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc <= 0x7f)
		ft_putchar_fd(wc, fd);
	else if (wc <= 0x7ff)
	{
		ft_putchar_fd((wc >> 6) + 0xc0, fd);
		ft_putchar_fd((wc & 0x3f) + 0x80, fd);
		return (2);
	}
	else if (wc <= 0xffff)
	{
		ft_putchar_fd((wc >> 12) + 0xe0, fd);
		ft_putchar_fd(((wc >> 6) & 0x3f) + 0x80, fd);
		ft_putchar_fd((wc & 0x3f) + 0x80, fd);
		return (3);
	}
	else if (wc <= 0x10ffff)
	{
		ft_putchar_fd((wc >> 18) + 0xf0, fd);
		ft_putchar_fd(((wc >> 12) & 0x3f) + 0x80, fd);
		ft_putchar_fd(((wc >> 6) & 0x3f) + 0x80, fd);
		ft_putchar_fd((wc & 0x3f) + 0x80, fd);
		return (4);
	}
	return (1);
}
