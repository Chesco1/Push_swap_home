/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_arg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 11:44:36 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 17:13:56 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_length(const char *format_arg, t_format *arg, int *i)
{
	if (format_arg[1] == 'h' && format_arg[0] == 'h')
		LENGTH = 5;
	else if (format_arg[0] == 'h')
		LENGTH = 4;
	else if (format_arg[1] == 'l' && format_arg[0] == 'l')
		LENGTH = 3;
	else if (format_arg[0] == 'l')
		LENGTH = 2;
	else if (format_arg[0] == 'L')
		LENGTH = 1;
	else if (format_arg[0] == 'j' || format_arg[0] == 'z' ||
			format_arg[0] == 't')
	{
		LENGTH = 3;
		(*i)++;
		return ;
	}
	if (LENGTH == 3 || LENGTH == 5)
		*i += 2;
	else if (LENGTH != 0)
		(*i)++;
}

static void	set_precision(const char *format_arg, t_format *arg,
		int *i, va_list *ap)
{
	char	*temp;
	int		j;

	j = 1;
	if (format_arg[j] == '*')
	{
		PRECISION = va_arg(*ap, int);
		*i += (j + 1);
		return ;
	}
	while (format_arg[j] >= '0' && format_arg[j] <= '9')
		j++;
	*i += j;
	temp = ft_strsub(&format_arg[1], 0, j);
	PRECISION = ft_atoi(temp);
	free(temp);
}

static void	set_width(const char *format_arg, t_format *arg,
		int len, va_list *ap)
{
	char	*temp;

	if (format_arg[0] == '*')
	{
		WIDTH = va_arg(*ap, int);
		return ;
	}
	else if (len == 0)
		return ;
	temp = ft_strsub(format_arg, 0, len);
	WIDTH = ft_atoi(temp);
	free(temp);
}

static void	set_flags(const char *flags, t_format *arg, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (flags[i] == '-')
			FLAGS |= 1;
		else if (flags[i] == '+')
			FLAGS |= 2;
		else if (flags[i] == '#')
			FLAGS |= 4;
		else if (flags[i] == '0')
			FLAGS |= 8;
		else if (flags[i] == ' ')
			FLAGS |= 16;
		else if (flags[i] == '_')
			FLAGS |= 32;
		else if (flags[i] == '^')
			FLAGS |= 64;
		else if (flags[i] == '=')
			FLAGS |= 128;
		i++;
	}
}

void		set_arg(t_format *arg, const char *format_arg, va_list *ap)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (format_arg[i] == '+' || format_arg[i] == '-' ||
			format_arg[i] == '0' || format_arg[i] == ' ' ||
			format_arg[i] == '#' || format_arg[i] == '_' ||
			format_arg[i] == '^' || format_arg[i] == 'U' ||
			format_arg[i] == '=')
		i++;
	set_flags(format_arg, arg, i);
	j = i;
	while ((format_arg[i] >= '0' && format_arg[i] <= '9')
			|| format_arg[i] == '*')
		i++;
	set_width(&format_arg[j], arg, (i - j), ap);
	j = i;
	if (format_arg[i] == '.')
		set_precision(&format_arg[i], arg, &i, ap);
	set_length(&format_arg[i], arg, &i);
	SPECIFIER = format_arg[i];
	INDEX_SPECIFIER = i;
}
