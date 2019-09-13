/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small_amount.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 15:14:32 by ccoers        #+#    #+#                 */
/*   Updated: 2019/09/12 15:14:34 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three_a(t_stacks *info)
{
    if (LEN_A == 3)
    {
        while (is_sorted(info, 'A') == 0)
        {
            if (A[0] > A[1] && A[0] > A[2])
                rotate_a(info);
            else if (A[1] < A[0] && A[1] < A[2]  && is_sorted(info, 'A') == 0)
                swap_a(info);
            else if (A[1] > A[0] && A[1] > A[2])
                reverse_rotate_a(info);
        }
    }
}