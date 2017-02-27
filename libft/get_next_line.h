/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:50:19 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/26 16:00:24 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 4096

typedef struct			s_lstline
{
	char				*str;
	int					fd;
	struct s_lstline	*next;
}						t_lstline;
int						get_next_line(const int fd, char **line);

#endif
