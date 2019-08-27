/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   correct_stacks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 12:57:20 by ccoers        #+#    #+#                 */
/*   Updated: 2019/08/27 12:57:23 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    correct_stack_b(t_stacks *info)
{
    if (ft_lstlen(B_PARTITIONS) > 1)
    {
        while (OFFSET_B > 0)
        {
            execute_command(info, "rrb");
            OFFSET_B--;
        }
    }
    OFFSET_B = 0;
}

void    correct_stack_a(t_stacks *info)
{
    int i;
    int to_bottom;
    char op[4];

    i = 0;
    ft_strcpy(op, "ra");
    to_bottom = ft_max_mult(A, LEN_A);
    while (A[i] != to_bottom)
        i++;
    if (i > LEN_A / 2)
        ft_strcpy(op, "rra");
    while (A[LEN_A - 1] != to_bottom)
        execute_command(info, op);
}