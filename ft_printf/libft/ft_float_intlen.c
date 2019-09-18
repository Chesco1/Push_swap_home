/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_intlen.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 11:28:46 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 14:26:39 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_float_intlen(long double n)
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
		n /= 10;
		i++;
	}
	return (i);
}