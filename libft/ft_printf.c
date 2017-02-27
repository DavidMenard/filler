/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:27:39 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/26 07:12:58 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_fstring(char *str, size_t start, size_t end, int fd)
{
	size_t len;

	len = end - start;
	write(fd, str + start, len);
	return ((int)len);
}

int		pft_core(va_list ap, char *format)
{
	int		ret;
	size_t	i[3];
	t_conv	convdata;

	convdata.fd = 1;
	i[0] = 0;
	ret = 0;
	while (format[i[0]])
	{
		i[1] = i[0];
		while (format[i[0]] && format[i[0]] != '%')
			i[0]++;
		ret += pft_fstring(format, i[1], i[0], convdata.fd);
		if (!format[i[0]])
			return (ret);
		i[1] = i[0]++;
		while (format[i[0]] && !pft_isconv(format[i[0]]))
			i[0]++;
		if (format[i[0]])
			i[0]++;
		if ((i[2] = pft_parse_conv(format, i, ap, &convdata)) == (size_t)-1)
			return (-1);
		ret += i[2];
	}
	return (ret);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = pft_core(ap, (char *)format);
	va_end(ap);
	return (ret);
}
