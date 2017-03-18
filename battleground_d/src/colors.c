/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:50:44 by dmenard           #+#    #+#             */
/*   Updated: 2017/03/18 15:39:33 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battle.h"

static	void	sft_colors_init(void)
{
	init_color(40, 1000, 454, 196);
	init_color(41, 1000, 536, 210);
	init_color(42, 1000, 590, 220);
	init_color(43, 492, 760, 824);
	init_color(44, 560, 816, 876);
	init_color(45, 700, 900, 1000);
	init_color(30, 1000, 454, 196);
	init_color(31, 492, 760, 824);
	init_color(32, 600, 200, 50);
	init_color(33, 700, 250, 100);
	init_color(34, 800, 300, 150);
	init_color(35, 1000, 400, 200);
	init_color(36, 900, 700, 200);
	init_color(37, 1000, 1000, 600);
}

void			ft_custome_colors(void)
{
	sft_colors_init();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, 30, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, 30);
	init_pair(5, 31, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, 31);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, 32, COLOR_BLACK);
	init_pair(9, 33, COLOR_BLACK);
	init_pair(10, 34, COLOR_BLACK);
	init_pair(11, 35, COLOR_BLACK);
	init_pair(12, 36, COLOR_BLACK);
	init_pair(13, 37, COLOR_BLACK);
	init_pair(14, 40, COLOR_BLACK);
	init_pair(15, 41, COLOR_BLACK);
	init_pair(16, 42, COLOR_BLACK);
	init_pair(17, 43, COLOR_BLACK);
	init_pair(18, 44, COLOR_BLACK);
	init_pair(19, 45, COLOR_BLACK);
}

void			ft_standard_colors(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(11, COLOR_YELLOW, COLOR_BLACK);
	init_pair(12, COLOR_YELLOW, COLOR_BLACK);
	init_pair(13, COLOR_WHITE, COLOR_BLACK);
	init_pair(14, COLOR_RED, COLOR_BLACK);
	init_pair(15, COLOR_RED, COLOR_BLACK);
	init_pair(16, COLOR_RED, COLOR_BLACK);
	init_pair(17, COLOR_CYAN, COLOR_BLACK);
	init_pair(18, COLOR_CYAN, COLOR_BLACK);
	init_pair(19, COLOR_CYAN, COLOR_BLACK);
}
