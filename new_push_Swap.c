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

void	back_to_b(t_stacks *info, int amt_last_to_a)
{
	int pivot;
	int closest;
	char op_to_closest[4];
	int amt_last_to_b;

	amt_last_to_b = 0;
	while (amt_last_to_b < amt_last_to_a / 2)
    {
		amt_last_to_b = 0;
		pivot = find_nbr_n(A, amt_last_to_a, (amt_last_to_a / 2) + 1);
    	closest = find_closest_A(info, pivot, op_to_closest);
        while (closest < pivot)
        {
			push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
			amt_last_to_b++;
        }
		check_swap(info);
		// recursion(info, , amt_last_to_b, amt_last_to_a)   de vergelijkbare denk ik
    }
}

void	recursion1(t_stacks *info, int begin_len, int amt_last_to_b, int last_push_to_a) //vergelijkbare schrijven
{
	int nb;
	int pivot;
	int closest;
	char op_to_closest[4];
	int amt_last_to_a;

	amt_last_to_a = 0;
	nb = begin_len;
	if (LEN_B == 0 || (nb / 2 == last_push_to_a))
		return ;
	while (nb / 2 > last_push_to_a && nb / 2 >= amt_last_to_b)
		nb /= 2;
	pivot = find_nbr_n(B, nb, 1);
	closest = find_closest_B(info, pivot, op_to_closest);
	while (closest >= pivot && LEN_B > 0)
    {
		push_closest_a(info, closest, op_to_closest);
		check_swap(info);
    	closest = find_closest_B(info, pivot, op_to_closest);
		amt_last_to_a++;
    }
	if (amt_last_to_a > 2)
		back_to_b(info, amt_last_to_a);
	print_stacks(info);
	recursion(info, begin_len, amt_last_to_b, amt_last_to_a);
}

void	initial_push(t_stacks *info)
{
    int pivot;
    int closest;
    char op_to_closest[4];
	int begin_len;
	int amt_last_to_b;

	begin_len = LEN_A;
    while (LEN_A > 2)
    {
		amt_last_to_b = 0;
		print_stacks(info);
        pivot = find_nbr_n(A, LEN_A, (LEN_A / 2) + 1);
        closest = find_closest_A(info, pivot, op_to_closest);
        while (closest < pivot)
        {
            push_closest_b(info, closest, op_to_closest);
            closest = find_closest_A(info, pivot, op_to_closest);
			amt_last_to_b++;
        }
		check_swap(info);
    }
	print_stacks(info);
	recursion(info, begin_len, amt_last_to_b, 0);
}
