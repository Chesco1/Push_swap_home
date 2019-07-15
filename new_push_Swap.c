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

void		recursion(t_stacks *info, int begin_len, int last_push)
{
	int nb;
	int pivot;
	int closest;
	char op_to_closest[4];

	nb = begin_len;
	while (nb / 2 > last_push)
	{
		nb /= 2;
	}
	pivot = find_nbr_n(B, nb, ft_max(nb / 2, 1));
	closest = find_closest_B(info, pivot, op_to_closest);
	ft_printf("closest: %i\npivot: %i\n", closest, pivot);
	while (closest >= pivot)
    {
		push_closest_a(info, closest, op_to_closest);
    	closest = find_closest_B(info, pivot, op_to_closest);
    }
	
}

void	initial_push(t_stacks *info)
{
    int pivot;
    int closest;
    char op_to_closest[4];
	int begin_len;

	begin_len = LEN_A;
    while (LEN_A > 2)
    {
		print_stacks(info);
        pivot = find_nbr_n(A, LEN_A, (LEN_A / 2) + 1);
        closest = find_closest_A(info, pivot, op_to_closest);
        while (closest < pivot)
        {
            push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
        }
    }
	check_swap(info);
	recursion(info, begin_len, 0);
}

// int      recursion(int nummer, t_stacks *info)
// {

// }

// void    new_push_swap(t_stacks *info)
// {
//     int pivot;

//     pivot = find_nbr_n(A, LEN_A, LEN_A / 2);
// }