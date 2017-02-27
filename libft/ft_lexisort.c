/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexisort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:11:28 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/04 19:59:11 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	start = starting index.
**	end = last index to check
*/

char		**ft_lexisort(char **tab, int start, int end)
{
	ft_strquicksort(tab, start, end, &ft_strcmp);
	return (tab);
}
