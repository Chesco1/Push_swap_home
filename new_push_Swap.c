/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 12:19:35 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:17:56 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check_swap(t_stacks *info)
{
	if (LEN_A >= 2)
	{
		if (A[0] > A[1])
		{
			if (B[0] < B[1])
				swap_both(info);
			else
				swap_a(info);
		}
	}
}

void			push_back_to_b(t_stacks *info)
{
	int		pivot;
	int		closest;
	char	op_to_closest[4];
	int		last_to_b;
	int		i;

	i = 0;
	while (LEFT_IN_PARTITION_A > 2)
	{
		last_to_b = 0;
		pivot = find_nbr_n(A, LEFT_IN_PARTITION_A,
		ft_max(((LEFT_IN_PARTITION_A / 2) + 1), 1));
		closest = find_closest_a(info, pivot, op_to_closest);
		while (closest < pivot)
		{
			push_closest_b(info, closest, op_to_closest);
			closest = find_closest_a(info, pivot, op_to_closest);
			last_to_b++;
		}
		correct_stack_a(info);
		update_partitions(info, 'B', last_to_b);
		i++;
	}
	check_swap(info);
	push_back_to_a(info);
}

static void		back_to_a_while_loop(t_stacks *info,
				int closest, int pivot, char *op_to_closest)
{
	while (closest >= pivot && LEFT_IN_PARTITION_B > 0)
	{
		push_closest_a(info, closest, op_to_closest);
		closest = find_closest_b(info, pivot, op_to_closest);
		LAST_TO_A++;
		LEFT_IN_PARTITION_B--;
	}
}

void			push_back_to_a(t_stacks *info)
{
	int		pivot;
	int		closest;
	char	op_to_closest[4];
	int		bottom_nb;

	bottom_nb = B[LEN_B - 1];
	if (LEFT_IN_PARTITION_B > 0)
	{
		LAST_TO_A = 0;
		pivot = find_nbr_n(B, LEFT_IN_PARTITION_B,
		ft_max((LEFT_IN_PARTITION_B / 2 + 1), 1));
		if (LEFT_IN_PARTITION_B == 2)
			pivot = find_nbr_n(B, LEFT_IN_PARTITION_B, 2);
		closest = find_closest_b(info, pivot, op_to_closest);
		back_to_a_while_loop(info, closest, pivot, op_to_closest);
		if (ft_lstlen(B_PARTITIONS) > 1)
			correct_stack_b(info, bottom_nb);
		update_partitions(info, 'A', LAST_TO_A);
		check_swap(info);
	}
	if (is_done(info) == 0)
		push_back_to_b(info);
}

void			initial_push(t_stacks *info)
{
	int		pivot;
	int		closest;
	char	op_to_closest[4];
	int		last_to_b;

	while (LEN_A > 3)
	{
		last_to_b = 0;
		pivot = find_nbr_n(A, LEN_A, (LEN_A / 2) + 1);
		closest = find_closest_a(info, pivot, op_to_closest);
		while (closest < pivot && LEN_A > 3)
		{
			push_closest_b(info, closest, op_to_closest);
			closest = find_closest_a(info, pivot, op_to_closest);
			last_to_b++;
		}
		update_partitions(info, 'B', last_to_b);
	}
	if (LEN_A == 3)
		sort_three_a(info);
	check_swap(info);
	if (is_done(info) == 0)
		push_back_to_a(info);
}
