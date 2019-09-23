/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_done.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 16:26:57 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:17:07 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stacks *info, char stack)
{
	int i;

	i = 0;
	if (stack == 'A')
	{
		while (i + 1 < LEN_A)
		{
			if (A[i] > A[i + 1])
			{
				return (0);
			}
			i++;
		}
	}
	else
	{
		while (i + 1 < LEN_B)
		{
			if (B[i] < B[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int		is_done(t_stacks *info)
{
	if (is_sorted(info, 'A') == 1 && LEN_B == 0)
		return (1);
	return (0);
}
