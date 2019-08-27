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

int		ft_max_mult(int *values, int len)
{
    int i;
    int biggest;

    i = 1;
    biggest = values[0];
    while (i < len)
    {
        if (values[i] > biggest)
            biggest = values[i];
        i++;
    }
    return (biggest);
}
