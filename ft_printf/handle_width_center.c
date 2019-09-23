/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_width_center.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 16:58:16 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 14:47:02 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_width_center(t_format *arg, t_print_info *print_info, int len)
{
	int i;

	i = 0;
	TO_PRINT = ft_strnew(LEN_OUTPUT + 1);
	check_sign_width(arg, print_info, &i, &len);
	while (len + (i * 2) < LEN_OUTPUT)
	{
		TO_PRINT[i] = PADDING_CHAR;
		i++;
	}
	ft_strcpy(&TO_PRINT[i], RESULT);
	i += len;
	free(RESULT);
	while (i < LEN_OUTPUT)
	{
		TO_PRINT[i] = PADDING_CHAR;
		i++;
	}
	TO_PRINT[i] = '\0';
	return (0);
}
