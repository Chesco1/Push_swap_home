/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_edge_float.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:50:41 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/24 14:58:42 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hash(t_format *arg)
{
	int len;
	int index_e;

	index_e = ft_max(ft_strchr_int(RESULT, 'e'),
					ft_strchr_int(RESULT, 'E'));
	if (FLAGS & 4)
	{
		if (index_e == -1)
		{
			len = ft_strlen(RESULT);
			RESULT[len] = '.';
			RESULT[len + 1] = '\0';
		}
		else if (index_e == 1 || index_e == 2)
		{
			ft_memmove(&RESULT[index_e + 1], &RESULT[index_e],
						ft_strlen(&RESULT[index_e]) + 1);
			RESULT[index_e] = '.';
		}
	}
}

int		check_edge_float(long double n, t_format *arg)
{
	if (n != n)
	{
		if (ft_isupper(SPECIFIER) == 1)
			RESULT = ft_strdup("NAN");
		else
			RESULT = ft_strdup("nan");
		return (TRUE);
	}
	else if (1 / 0.0 == n)
	{
		if (ft_isupper(SPECIFIER) == 1)
			RESULT = ft_strdup("INF");
		else
			RESULT = ft_strdup("inf");
		return (TRUE);
	}
	else if (1 / -0.0 == n)
	{
		if (ft_isupper(SPECIFIER) == 1)
			RESULT = ft_strdup("-INF");
		else
			RESULT = ft_strdup("-inf");
		return (TRUE);
	}
	return (FALSE);
}
