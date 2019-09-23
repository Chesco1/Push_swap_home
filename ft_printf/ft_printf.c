/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <avan-rei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:38:07 by avan-rei       #+#    #+#                */
/*   Updated: 2019/09/23 14:34:29 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format_str(const char *format_str, va_list *ap,
		t_print_info *print_info)
{
	t_format		*arg;
	int				save;

	arg = (t_format *)malloc(sizeof(t_format));
	FLAGS = 0;
	WIDTH = 0;
	PRECISION = -1;
	LENGTH = 0;
	SPECIFIER = 0;
	PRECISION_WAS_SET = 1;
	set_arg(arg, format_str, ap);
	if (PRECISION == -1)
		default_precision(arg);
	set_result(ap, arg);
	set_to_print(arg, print_info);
	save = INDEX_SPECIFIER + 2;
	free(arg);
	return (save);
}

static int	print(const char *format, va_list *ap, t_print_info *print_info)
{
	int				i;
	int				j;
	int				amount_printed;

	i = 0;
	j = 0;
	amount_printed = 0;
	while (format[i] != '\0')
	{
		set_color(&format[i], &i);
		j = i;
		while (format[i] != '%' && format[i] != '\0')
			i++;
		amount_printed += write(1, &format[j], i - j);
		if (format[i] != '\0')
		{
			set_color(&format[i + 1], &i);
			i += process_format_str(&format[i + 1], ap, print_info);
			amount_printed += write(1, TO_PRINT, LEN_OUTPUT);
			free(TO_PRINT);
		}
	}
	return (amount_printed);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_print_info	*print_info;
	int				amount_printed;

	amount_printed = 0;
	print_info = (t_print_info *)malloc(sizeof(t_print_info));
	va_start(ap, format);
	amount_printed = print(format, &ap, print_info);
	free(print_info);
	va_end(ap);
	write(1, "\033[0m", 5);
	return (amount_printed);
}
