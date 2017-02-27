/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:36:11 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/04 20:24:57 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strquicksort(
char **sort, int start, int end, int fp(const char*, const char*))
{
	int		i;
	int		j;
	char	*pivot;
	char	*swap;

	i = start;
	j = end;
	pivot = sort[(start + end) / 2];
	while (i <= j)
	{
		while (fp(pivot, sort[i]) > 0)
			++i;
		while (fp(pivot, sort[j]) < 0)
			--j;
		if (i <= j)
		{
			swap = sort[i];
			sort[i++] = sort[j];
			sort[j--] = swap;
		}
	}
	if (start < j)
		ft_strquicksort(sort, start, j, fp);
	if (end > i)
		ft_strquicksort(sort, i, end, fp);
}
