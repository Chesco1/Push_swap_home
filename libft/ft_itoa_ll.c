/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_ll.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:22:35 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 17:08:09 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_ll(long long nb)
{
	int		i;
	char	*str;

	if (nb == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	str = (char *)malloc(sizeof(char) * ft_ll_len(nb) + 1);
	if (str == NULL)
		return (NULL);
	i = ft_ll_len(nb) - 1;
	str[i + 1] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[i] = (nb % 10) + 48;
		i--;
		nb = nb / 10;
	}
	str[i] = nb + 48;
	return (str);
}
