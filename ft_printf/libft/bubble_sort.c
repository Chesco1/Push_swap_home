/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 16:38:49 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 14:47:39 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sorted(int *values, int len, char direction)
{
	int i;

	i = 0;
	if (direction == 'a')
	{
		while (i + 1 < len)
		{
			if (values[i] > values[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i + 1 < len)
		{
			if (values[i] < values[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

void			bubble_sort(int *values, int len, char direction)
{
	int i;

	while (is_sorted(values, len, direction) == 0)
	{
		i = 0;
		while (i + 1 < len)
		{
			if (direction == 'a')
			{
				if (values[i] > values[i + 1])
					ft_swap(&values[i], &values[i + 1]);
			}
			else
			{
				if (values[i] < values[i + 1])
					ft_swap(&values[i], &values[i + 1]);
			}
			i++;
		}
	}
}
