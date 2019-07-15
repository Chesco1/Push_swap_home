/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sciftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 12:34:34 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/24 15:22:25 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_negative(long double *n, char *str, int *i)
{
	if (*n < 0.0)
	{
		*n = -*n;
		str[0] = '-';
		(*i)++;
	}
}

static int	get_starting_index(int precision)
{
	if (precision != 0)
		return (precision + 2);
	else
		return (precision + 1);
}

char		*sciftoa(long double n, int precision, char c)
{
	int		power;
	char	*str;
	int		i;

	power = 0;
	str = ft_strnew(precision + 8);
	i = get_starting_index(precision);
	if (str == NULL)
		return (NULL);
	check_negative(&n, str, &i);
	while (n >= 10)
	{
		n /= 10;
		power++;
	}
	ft_strcat(str, ftoa(n, precision));
	str[i] = c;
	str[i + 1] = '+';
	if (power < 10)
	{
		str[i + 2] = '0';
		i++;
	}
	ft_strcpy(&str[i + 2], ft_itoa(power));
	return (str);
}
