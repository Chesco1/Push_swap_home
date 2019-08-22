/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 12:26:11 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/04 12:26:13 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_b(t_stacks *info)
{
    if (LEN_A > 0)
    {
        ft_memmove(&B[1], B, sizeof(int) * LEN_B);
        B[0] = A[0];
        LEN_B++;
        ft_memmove(A, &A[1], sizeof(int) * (LEN_A - 1));
        LEN_A--;
        LAST_OP = 5;
      //  ft_putendl("pb");
        if (PRINT == 1)
            print_stacks(info);
    }
}

void    push_a(t_stacks *info)
{
    if (LEN_B > 0)
    {
        ft_memmove(&A[1], A, sizeof(int) * LEN_A);
        A[0] = B[0];
        LEN_A++;
        ft_memmove(B, &B[1], sizeof(int) * (LEN_B - 1));
        LEN_B--;
        LAST_OP = 4;
     //   ft_putendl("pa");
        if (PRINT == 1)
            print_stacks(info);
    }
}