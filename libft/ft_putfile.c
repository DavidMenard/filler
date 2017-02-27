/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 11:22:04 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/18 11:52:58 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_putfile(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		write(1, &buffer, ret);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
