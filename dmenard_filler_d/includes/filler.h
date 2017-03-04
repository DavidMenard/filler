/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:18:14 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/04 08:48:37 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct		s_data
{
	int				pnbr;
	int				gx;
	int				gy;
}					t_data;

int				ft_parser(t_data *data);

#endif
