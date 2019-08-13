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

void	update_list(t_stacks *info, char stack_last_pushed, int left_from_partition)
{
	int half;

	half = left_from_partition / 2;
	if (stack_last_pushed == 'B')
	{
		ft_lstadd(&TO_PUSH_TO_A, ft_lstnew("hoi", ft_max(half, 1)));
	}
}

void	push_back_to_a(t_stacks *info)
{
	int pivot;
	int closest;
	char op_to_closest[4];

	LAST_TO_A = 0;
	pivot = find_nbr_n(B, LAST_TO_B, ft_max((LAST_TO_B / 2), 1));
	closest = find_closest_B(info, pivot, op_to_closest);
	while (closest >= pivot)
    {
        push_closest_a(info, closest, op_to_closest);
    	closest = find_closest_B(info, pivot, op_to_closest);
		LAST_TO_A++;
    }
	ft_lst_remove_first(&TO_PUSH_TO_A);
	check_swap(info);
}

void	initial_push(t_stacks *info)
{
    int pivot;
    int closest;
    char op_to_closest[4];

    while (LEN_A > 2)
    {
		LAST_TO_B = 0;
		print_stacks(info);
        pivot = find_nbr_n(A, LEN_A, (LEN_A / 2) + 1);
        closest = find_closest_A(info, pivot, op_to_closest);
        while (closest < pivot)
        {
            push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
			LAST_TO_B++;
        }
		update_list(info, 'B', LAST_TO_B);
		check_swap(info);
    }
	print_stacks(info);
	push_back_to_a(info);
	print_stacks(info);
}
