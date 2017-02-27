/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_str_switch_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:46:28 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/06 16:57:07 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pft_str_switch_d(va_list ap, t_conv *cd, int *sign)
{
	unsigned char	v1;
	char			*str;

	if (cd->size == 'H')
	{
		v = va_arg(unsigned char);
		if (cd->precise && cd->precision == 0 && v == 0)
			str = ft_strdup("");
		else if (!(str = ft_itoa_max_abs(v)))
			return (NULL);
		sign = 0;
	}
}
