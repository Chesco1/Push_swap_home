/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_partitions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 14:49:38 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:23:35 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_partitions(t_stacks *info, char stack_last_pushed,
		int amount_last_pushed)
{
	if (stack_last_pushed == 'B')
	{
		if (LEFT_IN_PARTITION_A > 2)
			LEFT_IN_PARTITION_A -= amount_last_pushed;
		ft_lstadd(&B_PARTITIONS, ft_lstnew_b("hoi", amount_last_pushed));
	}
	else if (stack_last_pushed == 'A')
		LEFT_IN_PARTITION_A = amount_last_pushed;
	if (LEFT_IN_PARTITION_B == 0)
		ft_lst_remove_first(&B_PARTITIONS);
}
