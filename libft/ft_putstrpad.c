/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:14:19 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/08 17:00:49 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrpad(char const *s, int nb, char c)
{
	char	buffer[nb];
	int		i;

	if (nb < 0)
		return ;
	if (!s)
		return ;
	i = ft_strlen(s);
	ft_strcpy(buffer, s);
	while (i < nb)
		buffer[i++] = c;
	write(1, buffer, i);
}
