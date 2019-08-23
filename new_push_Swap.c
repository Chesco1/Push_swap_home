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
	if (stack_last_pushed == 'B')
	{
		if (LEFT_IN_PARTITION_A > 2)
		{
			LEFT_IN_PARTITION_A -= amount_last_pushed;
		}
		ft_lstadd(&B_PARTITIONS, ft_lstnew("hoi", amount_last_pushed));
	}
	else if (stack_last_pushed == 'A')
	{
		LEFT_IN_PARTITION_A = amount_last_pushed;
	}
	if (LEFT_IN_PARTITION_B == 0)
	{
		ft_lst_remove_first(&B_PARTITIONS);
	}
}

void	push_back_to_b(t_stacks *info)
{
    int pivot;
    int closest;
    char op_to_closest[4];
	int last_to_b;
	int i = 0;

	ft_putendl("hoi");
    while (LEFT_IN_PARTITION_A > 2)
    {
		ft_printf("CLOSEST = %i\nPIVOT = %i, %i\n\n", closest, pivot, LEFT_IN_PARTITION_A);
		last_to_b = 0;
        pivot = find_nbr_n(A, LEFT_IN_PARTITION_A, ft_max(((LEFT_IN_PARTITION_A / 2)+ 1), 1));
        closest = find_closest_A(info, pivot, op_to_closest);
        while (closest <= pivot)
        {
            push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
			last_to_b++;
        }
		update_partitions(info, 'B', last_to_b);
		check_swap(info);
		print_stacks(info);
		i++;
    }
	// if (LEFT_IN_PARTITION_A == 2)
	// 	LEFT_IN_PARTITION_A = 0;
	push_back_to_a(info);
}

void	push_back_to_a(t_stacks *info)
{
	int pivot;
	int closest;
	char op_to_closest[4];
	int last_to_a;
	int i = 0;

	// if (LEFT_IN_PARTITION_B > 0)
	// {
		last_to_a = 0;
		pivot = find_nbr_n(B, LEFT_IN_PARTITION_B, ft_max((LEFT_IN_PARTITION_B / 2), 1));
		closest = find_closest_B(info, pivot, op_to_closest);
		while (closest >= pivot && LEFT_IN_PARTITION_B > 0)
    	{
			ft_printf("CLOSEST = %i\nPIVOT = %i\nLEFT_IN_PARTITION_A = %i\nLEFT_IN_PARTITION_B = %i\n\n", closest, pivot, LEFT_IN_PARTITION_A, LEFT_IN_PARTITION_B);
        	push_closest_a(info, closest, op_to_closest);
    		closest = find_closest_B(info, pivot, op_to_closest);
			last_to_a++;
			i++;
			LEFT_IN_PARTITION_B--;
			if (pivot == closest)
		 		break ;
    	}
		update_partitions(info, 'A', last_to_a);
		check_swap(info);
		print_stacks(info);
	// }
	if (is_done(info) == 0)
		push_back_to_b(info);
	else
		ft_putendl("KLAAAAAAAR");
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
		print_stacks(info);
		update_partitions(info, 'B', last_to_b);
		check_swap(info);
    }
	push_back_to_a(info);
}

//ft_printf("CLOSEST = %i\nPIVOT = %i\n\n", closest, pivot);