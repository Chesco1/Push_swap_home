/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_adress.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 16:52:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/28 15:38:26 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_address(va_list *ap, t_format *arg)
{
	char					*hex_nb;
	long long unsigned int	address;

	address = va_arg(*ap, long long unsigned int);
	hex_nb = ft_itoa_base_llu(address, 16, 'l');
	RESULT = ft_strnew(2 + ft_strlen(hex_nb));
	RESULT[0] = '0';
	RESULT[1] = 'x';
	ft_strcpy(&RESULT[2], hex_nb);
	free(hex_nb);
}
