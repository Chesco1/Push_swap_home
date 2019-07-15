/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 12:26:18 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/04 12:26:20 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate_b_both(t_stacks *info)
{
    int temp;

    if (LEN_B > 1)
    {
        temp = B[0];
        ft_memmove(B, &B[1], sizeof(int) * (LEN_B - 1));
        B[LEN_B - 1] = temp;    
    }
}

static void    rotate_a_both(t_stacks *info)
{
    int temp;

    if (LEN_A > 1)
    {
        temp = A[0];
        ft_memmove(A, &A[1], sizeof(int) * (LEN_A - 1));
        A[LEN_A - 1] = temp;    
    }
}

void            rotate_both(t_stacks *info)
{
    rotate_a_both(info);
    rotate_b_both(info);
    LAST_OP = 8;
    ft_putendl("rr");
    if (PRINT == 1)
        print_stacks(info);
}

void            rotate_b(t_stacks *info)
{
    int temp;

    if (LEN_B > 1)
    {
        temp = B[0];
        ft_memmove(B, &B[1], sizeof(int) * (LEN_B - 1));
        B[LEN_B - 1] = temp;
        LAST_OP = 7;
        ft_putendl("rb");
        if (PRINT == 1)
            print_stacks(info);
    }
}

void            rotate_a(t_stacks *info)
{
    int temp;

    if (LEN_A > 1)
    {
        temp = A[0];
        ft_memmove(A, &A[1], sizeof(int) * (LEN_A - 1));
        A[LEN_A - 1] = temp;
        LAST_OP = 6;
        ft_putendl("ra");
        if (PRINT == 1)
            print_stacks(info);    
    }
}