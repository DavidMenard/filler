/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 09:46:32 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 09:47:28 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrpad_fd(char const *s, int nb, char c, int fd)
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
	write(fd, buffer, i);
}
