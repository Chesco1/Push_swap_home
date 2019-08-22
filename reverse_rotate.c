/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 12:27:59 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/04 12:28:00 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    reverse_rotate_b_both(t_stacks *info)
{
    int temp;

    if (LEN_B > 1)
    {
        temp = B[LEN_B - 1];
        ft_memmove(&B[1], B, sizeof(int) * (LEN_B - 1));
        B[0] = temp;
    }
}

static void    reverse_rotate_a_both(t_stacks *info)
{
    int temp;

    if (LEN_A > 1)
    {
        temp = A[LEN_A - 1];
        ft_memmove(&A[1], A, sizeof(int) * (LEN_A - 1));
        A[0] = temp;  
    }
}

void    reverse_rotate_both(t_stacks *info)
{
    reverse_rotate_a_both(info);
    reverse_rotate_b_both(info);
    LAST_OP = 11;
  //  ft_putendl("rrr");
    if (PRINT == 1)
        print_stacks(info);
}

void    reverse_rotate_b(t_stacks *info)
{
    int temp;

    if (LEN_B > 1)
    {
        temp = B[LEN_B - 1];
        ft_memmove(&B[1], B, sizeof(int) * (LEN_B - 1));
        B[0] = temp;
        LAST_OP = 10;
       // ft_putendl("rrb");
        if (PRINT == 1)
            print_stacks(info);
    }
}

void    reverse_rotate_a(t_stacks *info)
{
    int temp;

    if (LEN_A > 1)
    {
        temp = A[LEN_A - 1];
        ft_memmove(&A[1], A, sizeof(int) * (LEN_A - 1));
        A[0] = temp; 
        LAST_OP = 9;
      //  ft_putendl("rra");
        if (PRINT == 1)
            print_stacks(info); 
    }
}
