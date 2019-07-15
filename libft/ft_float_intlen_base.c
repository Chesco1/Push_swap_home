/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_intlen_base.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 15:02:16 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 14:26:25 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_float_intlen_base(long double n, int base)
{
	int i;

	i = 1;
	if (n < 0.0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= base;
		i++;
	}
	return (i);
}
