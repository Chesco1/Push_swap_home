/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_precision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 13:17:31 by avan-rei       #+#    #+#                */
/*   Updated: 2019/09/23 14:10:45 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_sign_precision(char *temp_result, t_format *arg,
		int *i, int *len)
{
	if (temp_result[0] == '-')
	{
		ft_memmove(temp_result, &temp_result[1], *len);
		temp_result[*len - 1] = '\0';
		RESULT[0] = '-';
		(*i)++;
		(*len)--;
	}
	else if (FLAGS & 2)
	{
		RESULT[0] = '+';
		(*i)++;
	}
}

void		default_precision(t_format *arg)
{
	if (SPECIFIER == 'f' || SPECIFIER == 'e' || SPECIFIER == 'E'
		|| SPECIFIER == 'g' || SPECIFIER == 'G')
		PRECISION = 6;
	else if (SPECIFIER == 's')
		PRECISION = FT_INT_MAX;
	else
	{
		PRECISION = 1;
		PRECISION_WAS_SET = 0;
	}
}

void		handle_precision(char *temp_result, t_format *arg)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(temp_result);
	RESULT = ft_strnew((ft_max(PRECISION, len) + 2));
	check_sign_precision(temp_result, arg, &i, &len);
	while (len < PRECISION)
	{
		RESULT[i] = '0';
		i++;
		len++;
	}
	ft_strcpy(&RESULT[i], temp_result);
	free(temp_result);
}
