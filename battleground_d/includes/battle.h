/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:18:14 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/02 13:36:36 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <ncurses.h>
# include <locale.h>

# define	BAN_HEIGHT	7
# define	BAN_WIDTH	110

typedef struct		s_turn
{
	char			**grid;
}					t_turn;

typedef struct		s_data
{
	t_turn			**turns;
	int				turn;
	int				turns_nbr;
	char			*p1_name;
	char			*p2_name;
	int				gridsize_x;
	int				gridsize_y;
	WINDOW			*win_grid;
	WINDOW			*win_ban;
	int				total_pieces;
	int				p1_pieces;
	int				p2_pieces;
	int				p1_control;
	int				p2_control;
	int				neutral_control;
}					t_data;

void				*ft_smalloc(size_t n);
void				ft_error(char *errmsg);
void				ft_input(t_data *data);
void				ft_get_scores(t_data *data);
void				ft_get_scores_back(t_data *data);

void				ft_parser(t_data *data);
void				ft_get_turns(t_data *data);

void				ft_update_win_grid(t_data *data);
void				ft_create_win_grid(t_data *data);

void				ft_create_win_ban(t_data *data);
void				ft_update_win_ban(t_data *data);

void				ft_debug_print_turns(t_data *data);
#endif
