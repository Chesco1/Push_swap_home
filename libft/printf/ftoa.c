/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftoa.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 14:35:48 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 18:07:12 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_round_up(long double n, char *str, int i)
{
	if (n > 0.5 || (n == 0.5 && str[i] == '.' &&
				ft_iseven(str[i - 1] - 48) == 0) ||
			(n == 0.5 && str[i] != '.' && ft_iseven(str[i] - 48) == 0))
		return (1);
	return (0);
}

static void	ft_round(long double n, char *str, int i)
{
	int		len;

	len = i + 1;
	if (to_round_up(n, str, i) == 1)
	{
		while (i >= 0 && (str[i] == '9' || str[i] == '.'))
		{
			if (str[i] == '9')
				str[i] = '0';
			i--;
		}
		if (i < 0)
		{
			ft_memmove(&str[1], str, len);
			len++;
			str[0] = '1';
		}
		else if (str[i] != '.')
			str[i] += 1;
		else if (str[i] == '.')
			str[i - 1] += 1;
	}
	str[len] = '\0';
	if (str[len - 1] == '.')
		str[len - 1] = '\0';
}

static void	check_negative_zero(char *str, int *intlen, long double *n)
{
	if (*n < 0.0 && str[0] != '-')
	{
		ft_memmove(&str[1], str, *intlen);
		str[0] = '-';
		(*intlen)++;
	}
}

char		*ftoa(long double n, int precision)
{
	char	*str;
	int		intlen;

	intlen = ft_float_intlen(n);
	str = (char *)malloc(sizeof(char) * intlen + precision + 4);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, ft_itoa_ll((long long int)n));
	str[intlen] = '.';
	intlen++;
	check_negative_zero(str, &intlen, &n);
	if (n < 0.0)
		n = -n;
	n -= (long long int)n;
	while (precision > 0)
	{
		n *= 10;
		str[intlen] = (int)n + 48;
		n -= (long long int)n;
		intlen++;
		precision--;
	}
	str[intlen] = '\0';
	ft_round(n, str, intlen - 1);
	return (str);
}
