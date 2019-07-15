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

int		ft_min_mult(int args, int *values)
{
    int             *copy;
    int             i;
    int             min;

    i = 0;
    copy = ft_intdup(values, args);
    while (i + 1 < args)
    {
        if (copy[i] < copy[i + 1])
            ft_swap(&copy[i], &copy[i + 1]);
        i++;
    }
    min = copy[i];
    free(copy);
    return (min);
}