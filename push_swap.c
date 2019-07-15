/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 12:24:24 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/04 12:24:27 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     sort_three(t_stacks *info, char stack)
{
    if (stack == 'A')
    {
        while (is_sorted(info, 'A') == 0)
        {
            if (A[0] > A[1] && A[0] > A[2])
                reverse_rotate_a(info);
            if (A[2] > A[1] && A[2] > A[0]  && is_sorted(info, 'A') == 0)
                swap_a(info);
            if (A[1] > A[0] && A[1] > A[2])
                rotate_a(info);
        }
    }
    else 
    {
        while (is_sorted(info, 'B') == 0)
        {
            if (B[0] < B[1] && B[0] < B[2])
                reverse_rotate_b(info);
            if (B[2] < B[1] && B[2] < B[0]  && is_sorted(info, 'B') == 0)
                swap_b(info);
            if (B[1] < B[0] && B[1] < B[2])
                rotate_b(info);
        }
    }
}

static void     check_swap(t_stacks *info)
{
    if (A[0] > A[1] && B[0] < B[1])
        swap_both(info);
    else if (A[0] > A[1])
        swap_a(info);
    else if (B[0] < B[1])
        swap_b(info);
}

void            push_swap(t_stacks *info)
{
    check_swap(info);
    push_b(info);
}