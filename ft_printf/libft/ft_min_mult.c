/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min_mult.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 15:21:45 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/06 15:21:46 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min_mult(int *values, int len)
{
    int i;
    int smallest;

    i = 1;
    smallest = values[0];
    while (i < len)
    {
        if (values[i] < smallest)
            smallest = values[i];
        i++;
    }
    return (smallest);
}