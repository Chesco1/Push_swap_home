/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 12:26:03 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/04 12:26:05 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap_b_both(t_stacks *info)
{
    if (LEN_B >= 2)
        ft_swap(&B[0], &B[1]);
}

static void    swap_a_both(t_stacks *info)
{
    if (LEN_A >= 2)
        ft_swap(&A[0], &A[1]);
}

void    swap_both(t_stacks *info)
{
    swap_a_both(info);
    swap_b_both(info);
    LAST_OP = 3;
    ft_putendl("ss");
}

void    swap_b(t_stacks *info)
{
    if (LEN_B >= 2)
    {
        ft_swap(&B[0], &B[1]);
        LAST_OP = 2;
        ft_putendl("sb");
    }
}

void    swap_a(t_stacks *info)
{
    if (LEN_A >= 2)
    {
        ft_swap(&A[0], &A[1]);
        LAST_OP = 1;
        ft_putendl("sa");
    }
}