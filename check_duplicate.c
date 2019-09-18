/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_duplicate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 16:49:04 by ccoers        #+#    #+#                 */
/*   Updated: 2019/09/18 16:49:05 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_duplicate(t_stacks *info)
{
	int i;
	int j;
	int	*temp;

	i = 0;
	j = 1;
	temp = A;
	while (i < LEN_A)
	{
		if (A[i] == temp[j] && i != j)
			ft_error();
		while (j < LEN_A)
		{
			if (A[i] == temp[j] && i != j)
				ft_error();
			j++;
		}
		j = 0;
		i++;
	}
}