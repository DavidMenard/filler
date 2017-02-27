/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 05:15:02 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 16:44:33 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *wstr)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (wstr[i])
		count += ft_wcharlen(wstr[i++]);
	return (count);
}
