/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_result.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 14:20:40 by avan-rei       #+#    #+#                */
/*   Updated: 2019/06/03 18:29:56 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*shortest(long double n, t_format *arg)
{
	int intlen_float;

	intlen_float = ft_float_intlen(n);
	if (intlen_float > PRECISION && intlen_float != 1)
	{
		if (SPECIFIER == 'g')
			return (sciftoa_sig(n, PRECISION, 'e'));
		else
			return (sciftoa_sig(n, PRECISION, 'E'));
	}
	return (ftoa_sig(n, PRECISION));
}

static void	cast_double(va_list *ap, t_format *arg)
{
	long double n;

	if (LENGTH == 1)
		n = va_arg(*ap, long double);
	else
		n = (long double)va_arg(*ap, double);
	if (check_edge_float(n, arg) == TRUE)
		return ;
	if (SPECIFIER == 'f' || SPECIFIER == 'F')
		RESULT = ftoa(n, PRECISION);
	else if (SPECIFIER == 'e' || SPECIFIER == 'E')
		RESULT = sciftoa(n, PRECISION, SPECIFIER);
	else if (SPECIFIER == 'g' || SPECIFIER == 'G')
		RESULT = shortest(n, arg);
	handle_precision(ft_strdup(RESULT), arg);
	handle_hash(arg);
}

static void	cast_unsigned_int(va_list *ap, t_format *arg, int base, char type)
{
	char	*temp_result;
	char	temp;

	if (LENGTH != 2 && LENGTH != 3)
		temp_result = ft_itoa_base_ui(va_arg(*ap, unsigned int), base, type);
	else
		temp_result = ft_itoa_base_llu(va_arg(*ap, long long unsigned int),
			base, type);
	temp = temp_result[0];
	handle_precision(temp_result, arg);
	if (FLAGS & 4 && SPECIFIER != 'u' && temp != '0')
	{
		if (SPECIFIER == 'o')
		{
			ft_memmove(&RESULT[1], RESULT, ft_strlen(RESULT));
			RESULT[0] = '0';
		}
		if (SPECIFIER == 'x' || SPECIFIER == 'X')
		{
			ft_memmove(&RESULT[2], RESULT, ft_strlen(RESULT));
			RESULT[0] = '0';
			RESULT[1] = SPECIFIER;
		}
	}
}

static void	cast_int(va_list *ap, t_format *arg)
{
	int		temp;
	char	*temp_result;

	if (SPECIFIER == 'c')
	{
		temp = va_arg(*ap, int);
		RESULT = ft_strndup((char *)&temp, 1);
		return ;
	}
	else if (LENGTH != 2 && LENGTH != 3)
		temp_result = ft_itoa(va_arg(*ap, int));
	else
		temp_result = ft_itoa_ll(va_arg(*ap, long long int));
	handle_precision(temp_result, arg);
}

void		set_result(va_list *ap, t_format *arg)
{
	if (SPECIFIER == 'i' || SPECIFIER == 'd' || SPECIFIER == 'c')
		cast_int(ap, arg);
	else if (SPECIFIER == 's')
		handle_str(ap, arg);
	else if (SPECIFIER == 'u')
		cast_unsigned_int(ap, arg, 10, 'l');
	else if (SPECIFIER == 'o')
		cast_unsigned_int(ap, arg, 8, 'l');
	else if (SPECIFIER == 'x')
		cast_unsigned_int(ap, arg, 16, 'l');
	else if (SPECIFIER == 'X')
		cast_unsigned_int(ap, arg, 16, 'u');
	else if (SPECIFIER == 'f' || SPECIFIER == 'F' || SPECIFIER == 'e' ||
			SPECIFIER == 'E' || SPECIFIER == 'g' || SPECIFIER == 'G')
		cast_double(ap, arg);
	else if (SPECIFIER == 'p')
		pointer_address(ap, arg);
	else if (SPECIFIER == '%')
		RESULT = ft_strdup("%");
	else if (SPECIFIER == 'b')
		cast_unsigned_int(ap, arg, 2, 'l');
	else if (SPECIFIER == '!')
		show_colors(arg);
	else
		RESULT = ft_strnew(0);
}
