/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_closest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 15:08:00 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/04 15:37:47 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_closest_a(t_stacks *info, int to_find, char *op_to_closest)
{
    int bottom_nb;
    
    bottom_nb = B[LEN_B - 1];
    while (B[0] != to_find)
        execute_command(info, op_to_closest);
    push_a(info);
    if (ft_lstlen(B_PARTITIONS) > 1)
    {
        while (B[LEN_B - 1] != bottom_nb)
        {
            execute_command(info, "rrb");
        }
    }
}

void    push_closest_b(t_stacks *info, int to_find, char *op_to_closest)
{
    while (A[0] != to_find)
        execute_command(info, op_to_closest);
    push_b(info);
}

int      find_closest_B(t_stacks *info, int pivot, char *op_to_closest)
{
    int i;
    int j;
    
    i = 1;
    j = LEN_B - 1;
    if (B[0] >= pivot)    //'=' was blind gokje
        return (B[0]);
    while (i < LEN_B)
    {
        if (B[i] >= pivot)
        {
            ft_strcpy(op_to_closest, "rb");
            return (B[i]);
        }
        if (B[j] >= pivot)
        {
            ft_strcpy(op_to_closest, "rrb");
            return (B[j]);
        }
        i++;
        j--;
    }
    ft_putendl("kippen");
    return (B[0]);
}

int      find_closest_A(t_stacks *info, int pivot, char *op_to_closest)
{
    int i;
    int j;
    
    i = 1;
    j = LEN_A - 1;
    if (A[0] < pivot)
        return (A[0]);
    while (i < LEN_A)
    {
        if (A[i] < pivot)
        {
            ft_strcpy(op_to_closest, "ra");
            return (A[i]);
        }
        else if (A[j] < pivot)
        {
            ft_strcpy(op_to_closest, "rra");
            return (A[j]);
        }
        i++;
        j--;
    }
    return (A[0]);
}