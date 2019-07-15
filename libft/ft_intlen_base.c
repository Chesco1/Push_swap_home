/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 17:04:36 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 17:10:15 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_base(int nb, int base)
{
	int i;

	i = 1;
	if (nb == -2147483648 && base == 10)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			i++;
	}
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}
