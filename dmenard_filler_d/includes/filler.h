/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:18:14 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/07 19:49:31 by dmenard          ###   ########.fr       */
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
	int				px;
	int				py;
	char			**piece;
	char			**grid;
}					t_data;

int				ft_parser(t_data *data);
int				ft_get_grid_size(t_data *data);
int				ft_get_grid(t_data *data);
int				ft_get_piece_size(t_data *data);
int				ft_get_piece(t_data *data);

void			ft_print_grid(t_data *data);

#endif
