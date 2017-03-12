/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:18:14 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/12 17:13:28 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct		s_move
{
	int				x;
	int				y;
	int				score;
}					t_move;
/*
typedef struct		s_weight
{
	int				dist_en;
}
*/
typedef struct		s_data
{
	int				pnbr;
	int				gx;
	int				gy;
	int				px;
	int				py;
	int				center_piece_x;
	int				center_piece_y;
	char			**piece;
	char			**grid;
	t_list			*moves;
}					t_data;

int				ft_parser(t_data *data);
int				ft_get_grid_size(t_data *data);
int				ft_get_grid(t_data *data);
int				ft_get_grid_turn(t_data *data);
int				ft_get_piece_size(t_data *data);
int				ft_get_piece(t_data *data);

void			ft_del_grid(t_data *data);
void			ft_del_piece(t_data *data);
void			ft_del_moves(t_data *data);

void			ft_make_move(t_data *data);
int				ft_get_score(t_data *data, int x, int y);

void			ft_print_grid(t_data *data);
void			ft_print_moves(t_data *data);
void			ft_print_input(void);
void			ft_print_piece(t_data *data);

int				ft_ismine(t_data *data, int x, int y);
int				ft_ishis(t_data *data, int x, int y);
int				ft_isfree(t_data *data, int x, int y);

#endif
