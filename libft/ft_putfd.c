/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:36:49 by dmenard           #+#    #+#             */
/*   Updated: 2016/11/04 14:59:42 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	ft_putfd(int fd)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		write(1, &buffer, ret);
	}
	return (0);
}
