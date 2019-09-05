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

void    correct_stack_b(t_stacks *info, int bottom_nb)
{
    int i;
    char op[4];

    i = 0;
    ft_strcpy(op, "rb");
    while (B[i] != bottom_nb)
        i++;
    if (i > LEN_B / 2)
        ft_strcpy(op, "rrb");
    while (B[LEN_B - 1] != bottom_nb)
        execute_command(info, op);
}