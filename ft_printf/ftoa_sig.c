/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftoa_sig.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:52:38 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/28 11:11:18 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	remove_zeroes(char *str, int i)
{
	while (str[i] == '0')
	{
		str[i] = '\0';
		i--;
	}
	if (str[i] == '.')
		str[i] = '\0';
	str[i] = '\0';
}

static int	to_round_up(long double n, char *str, int i)
{
	if (n > 0.5 || (n == 0.5 && str[i] == '.' &&
				ft_iseven(str[i - 1] - 48) == 0) ||
			(n == 0.5 && str[i] != '.' && ft_iseven(str[i] - 48) == 0))
		return (1);
	return (0);
}

static void	ft_round(long double n, char *str, int len)
{
	int		i;

	i = len - 1;
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
	if (str[len - 1] == '.')
		str[len - 1] = '\0';
	remove_zeroes(str, len - 1);
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

char		*ftoa_sig(long double n, int precision)
{
	char	*str;
	int		len;

	len = ft_float_intlen(n);
	str = (char *)malloc(sizeof(char) * len + precision + 4);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, ft_itoa_ll((long long int)n));
	str[len] = '.';
	len++;
	check_negative_zero(str, &len, &n);
	if (n < 0.0)
		n = -n;
	n -= (long long int)n;
	precision -= len - 1;
	while (precision > 0)
	{
		n *= 10;
		str[len] = (int)n + 48;
		n -= (long long int)n;
		len++;
		precision--;
	}
	ft_round(n, str, len);
	return (str);
}
