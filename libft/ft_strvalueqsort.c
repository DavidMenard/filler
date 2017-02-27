/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvalueqsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:46:41 by dmenard           #+#    #+#             */
/*   Updated: 2016/12/08 17:06:36 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sft_swap(long *vsort, char **sort, int i, int j)
{
	char	*swap;
	long	vswap;

	swap = sort[i];
	sort[i] = sort[j];
	sort[j] = swap;
	vswap = vsort[i];
	vsort[i] = vsort[j];
	vsort[j] = vswap;
}

void			ft_strvalueqsort(char **sort, long *vsort, int start, int end)
{
	int		i;
	int		j;
	long	pivot;

	i = start;
	j = end;
	pivot = vsort[(start + end) / 2];
	while (i <= j)
	{
		while (pivot - vsort[i] > 0)
			++i;
		while (pivot - vsort[j] < 0)
			--j;
		if (i <= j)
			sft_swap(vsort, sort, i++, j--);
	}
	if (start < j)
		ft_strvalueqsort(sort, vsort, start, j);
	if (end > i)
		ft_strvalueqsort(sort, vsort, i, end);
}
