/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:50:41 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/17 03:01:56 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLE_H
# define BATTLE_H

# include "libft.h"
# include <ncurses.h>
# include <locale.h>

# define BAN_HEIGHT	7
# define BAN_WIDTH	110

# define SHOW_LOADING 0

# define C_RED "\x1b[31m"
# define C_GREEN "\x1b[32m"
# define C_RESET "\x1b[0m"

typedef struct		s_turn
{
	char			**grid;
	int				p1_moves;
	int				p2_moves;
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
	int				p1_pieces;
	int				p2_pieces;
	int				frame;
	int				col_frame;
}					t_data;

void				*ft_smalloc(size_t n);
void				ft_error(char *errmsg);
int					ft_input(t_data *data);
void				ft_update_scores(t_data *data);

void				ft_parser(t_data *data);
void				ft_get_turns(t_data *data);

void				ft_update_display(t_data *data, char **grid, int p1s, int p2s);

void				ft_update_win_grid(t_data *data, char **grid);
void				ft_create_win_grid(t_data *data);

void				ft_create_win_ban(t_data *data);
void				ft_update_win_ban(t_data *data, int p1s, int p2s);

void				ft_debug_print_turns(t_data *data);
void				ft_print_grid(char **grid);
void				ft_print_loading(char **grid);
#endif
