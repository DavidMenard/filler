/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 05:51:46 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 16:45:17 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwstr(wchar_t *wstr)
{
	size_t i;
	size_t ret;

	i = 0;
	ret = 0;
	while (wstr[i])
		ret += ft_putwchar(wstr[i++]);
	return (ret);
}
