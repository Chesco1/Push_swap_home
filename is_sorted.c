/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 16:26:57 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/27 16:26:58 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_sorted(t_stacks *info, char stack)
{
    int i;

    i = 0;
    if (stack == 'A')
    {
        while (i + 1 < LEN_A)
        {
            if (i > i + 1)
                return (0);
            i++;
        }
    }
    else
    {
       while (i + 1 < LEN_B)
        {
            if (i < i + 1)
                return (0);
            i++;
        } 
    }
    return (1);
}