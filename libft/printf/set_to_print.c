/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_to_print.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:33:36 by avan-rei       #+#    #+#                */
/*   Updated: 2019/06/03 17:25:02 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_sign_width(t_format *arg, t_print_info *print_info,
		int *i, int *len)
{
	char temp;

	if (FLAGS & 16 && RESULT[0] != '-' && RESULT[0] != '+' && SPECIFIER != '%')
	{
		ft_memmove(&RESULT[1], RESULT, *len);
		RESULT[0] = ' ';
		(*len)++;
		if (*len > LEN_OUTPUT)
			LEN_OUTPUT++;
	}
	temp = RESULT[0];
	if (PADDING_CHAR == '0' && (RESULT[0] == '-' || RESULT[0] == '+'))
	{
		ft_memmove(RESULT, &RESULT[1], *len);
		RESULT[*len - 1] = '\0';
		TO_PRINT[0] = temp;
		(*i)++;
	}
	else if (PADDING_CHAR == '0' && RESULT[1] == 'x' && RESULT[0] == '0')
	{
		ft_memmove(RESULT, &RESULT[2], *len);
		RESULT[*len - 2] = '\0';
		ft_strcpy(TO_PRINT, "0x");
		*i += 2;
	}
}

static int	handle_width(t_format *arg, t_print_info *print_info, int len)
{
	int i;

	i = 0;
	if (JUSTIFICATION == 'c')
		return (handle_width_center(arg, print_info, len));
	TO_PRINT = ft_strnew(LEN_OUTPUT + 1);
	check_sign_width(arg, print_info, &i, &len);
	if (JUSTIFICATION == 'r')
	{
		while (len < LEN_OUTPUT)
		{
			TO_PRINT[i] = PADDING_CHAR;
			len++;
			i++;
		}
	}
	ft_strcpy(&TO_PRINT[i], RESULT);
	free(RESULT);
	while (JUSTIFICATION == 'l' && len < LEN_OUTPUT)
	{
		TO_PRINT[len] = PADDING_CHAR;
		len++;
	}
	TO_PRINT[len] = '\0';
	return (0);
}

char		set_padding_char(t_format *arg)
{
	if (FLAGS & 8 && (PRECISION_WAS_SET == 0 || SPECIFIER == 'f'
	|| SPECIFIER == 'F' || SPECIFIER == 'e' || SPECIFIER == 'E'
	|| SPECIFIER == 'g' || SPECIFIER == 'G'))
		return ('0');
	return (' ');
}

void		check_edge_zero(t_format *arg, t_print_info *print_info, int len)
{
	if (SPECIFIER != 'f')
	{
		if (PRECISION == 0 && RESULT[0] == '0' && len == 1)
		{
			if (SPECIFIER == 'o' && FLAGS & 4)
				return ;
			RESULT[0] = PADDING_CHAR;
			if (LEN_OUTPUT > WIDTH)
				LEN_OUTPUT--;
		}
	}
}

void		set_to_print(t_format *arg, t_print_info *print_info)
{
	int len;

	len = ft_strlen(RESULT);
	PADDING_CHAR = set_padding_char(arg);
	LEN_OUTPUT = ft_max(len, WIDTH);
	check_edge_zero(arg, print_info, len);
	if (FLAGS & 1)
		JUSTIFICATION = 'l';
	else if (FLAGS & 128)
		JUSTIFICATION = 'c';
	else
		JUSTIFICATION = 'r';
	handle_width(arg, print_info, len);
	if (SPECIFIER == 'c' && RESULT[0] == '\0' && WIDTH != 0 && FLAGS ^ 1)
		TO_PRINT[LEN_OUTPUT - 1] = '\0';
	else if (SPECIFIER == 'c' && RESULT[0] == '\0' && WIDTH != 0 && FLAGS & 1)
		TO_PRINT[0] = '\0';
	else if (SPECIFIER == 'c' && RESULT[0] == '\0')
		LEN_OUTPUT++;
	if (FLAGS & 32)
		TO_PRINT = ft_str_tolower(TO_PRINT);
	if (FLAGS & 64)
		TO_PRINT = ft_str_toupper(TO_PRINT);
}
