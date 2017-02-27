/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:18:14 by dmenard           #+#    #+#             */
/*   Updated: 2017/02/27 18:59:18 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct		s_turn
{
	char			**grid;
}

typedef struct		s_data
{
	t_turn			*turns;
	int				turns_nbr;
	char			*p1_name;
	char			*p2_name;
}					t_data;

void				*ft_smalloc(size_t n);
void				ft_error(char *errmsg);
void				ft_parser(t_data *data);

#endif
