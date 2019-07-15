/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   var_max.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:48:47 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/06 12:53:26 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max_mult(int args, int *values)
{
    int             *copy;
    int             i;
    int             max;

    i = 0;
    copy = ft_intdup(values, args);
    while (i + 1 < args)
    {
        if (copy[i] > copy[i + 1])
            ft_swap(&copy[i], &copy[i + 1]);
        i++;
    }
    max = copy[i];
    free(copy);
    return (max);
}
