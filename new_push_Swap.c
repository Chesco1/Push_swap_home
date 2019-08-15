/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_push_Swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 12:19:35 by ccoers        #+#    #+#                 */
/*   Updated: 2019/07/04 12:19:36 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_swap(t_stacks *info)
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

void	update_partitions(t_stacks *info, char stack_last_pushed, int amount_last_pushed)
{
	if (stack_last_pushed == 'A')
	{
		if (LEFT_IN_PARTITION_A <= 2)
			LEFT_IN_PARTITION_A -= amount_last_pushed;
		else 
		{
			ft_putendl("Something went wrong while trying to overwrite partition A");
			exit(1);
		}
	}
	else if (stack_last_pushed == 'B')
	{
		ft_lstadd(&B_PARTITIONS, ft_lstnew("hoi", LEFT_IN_PARTITION_B - amount_last_pushed));
	}
}

void	push_back_to_b(t_stacks *info)
{
    int pivot;
    int closest;
    char op_to_closest[4];
	int last_to_b;

    while (LEFT_IN_PARTITION_A > 2)
    {
		last_to_b = 0;
        pivot = find_nbr_n(A, LEFT_IN_PARTITION_A, (LEN_A / 2) + 1);
        closest = find_closest_A(info, pivot, op_to_closest);
        while (closest < pivot)
        {
            push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
			last_to_b++;
        }
		update_partitions(info, 'B', last_to_b);
		check_swap(info);
    }
	push_back_to_a(info);
}

void	push_back_to_a(t_stacks *info)
{
	int pivot;
	int closest;
	char op_to_closest[4];
	int last_to_a;

	last_to_a = 0;
	pivot = find_nbr_n(B, LEFT_IN_PARTITION_B, ft_max((LEFT_IN_PARTITION_B / 2), 1));
	closest = find_closest_B(info, pivot, op_to_closest);
	while (closest >= pivot)
    {
        push_closest_a(info, closest, op_to_closest);
    	closest = find_closest_B(info, pivot, op_to_closest);
		last_to_a++;
    }
	update_partitions(info, 'A', last_to_a);
	check_swap(info);
}

void	initial_push(t_stacks *info)
{
    int pivot;
    int closest;
    char op_to_closest[4];
	int last_to_b;

    while (LEN_A > 2)
    {
		last_to_b = 0;
		print_stacks(info);
        pivot = find_nbr_n(A, LEN_A, (LEN_A / 2) + 1);
        closest = find_closest_A(info, pivot, op_to_closest);
        while (closest < pivot)
        {
            push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
			last_to_b++;
        }
		update_partitions(info, 'B', last_to_b);
		check_swap(info);
    }
	print_stacks(info);
	push_back_to_a(info);
	print_stacks(info);
}
