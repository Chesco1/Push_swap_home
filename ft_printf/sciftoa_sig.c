/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sciftoa_sig.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:56:20 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/28 11:45:41 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	remove_zeroes(char *str, int *i)
{
	while (str[(*i) - 1] == '0')
	{
		str[(*i) - 1] = '\0';
		(*i)--;
	}
	if (str[(*i) - 1] == '.')
	{
		str[(*i) - 1] = '\0';
		(*i)--;
	}
}

static void	calc_power(long double *n, int power)
{
	while (*n >= 10)
	{
		*n /= 10;
		power++;
	}
}

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
	if (precision < 2)
		return (1);
	else
		return (precision + 1);
}

char		*sciftoa_sig(long double n, int precision, char c)
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
	calc_power(&n, power);
	ft_strcat(str, ftoa(n, precision - 1));
	remove_zeroes(str, &i);
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
