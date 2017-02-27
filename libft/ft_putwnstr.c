/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 05:49:08 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/04 06:10:19 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwnstr(wchar_t *wstr, size_t n)
{
	size_t i;
	size_t ret;

	i = 0;
	ret = 0;
	while (wstr[i] && i < n)
		ret += ft_putwchar(wstr[i++]);
	return (ret);
}
