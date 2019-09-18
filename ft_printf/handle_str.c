/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:03:49 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/24 18:21:30 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_str(va_list *ap, t_format *arg)
{
	char	*temp;

	temp = ft_strdup(va_arg(*ap, char *));
	if (temp == NULL)
		RESULT = ft_strdup("(null)");
	else
		RESULT = ft_strndup(temp, ft_min(PRECISION, ft_strlen(temp)));
	free(temp);
}
