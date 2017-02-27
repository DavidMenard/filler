/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 10:21:16 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 10:21:56 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwnstr_fd(wchar_t *wstr, size_t n, int fd)
{
	size_t i;
	size_t ret;

	i = 0;
	ret = 0;
	while (wstr[i] && i < n)
		ret += ft_putwchar_fd(wstr[i++], fd);
	return (ret);
}
