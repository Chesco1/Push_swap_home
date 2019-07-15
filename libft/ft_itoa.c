/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 17:04:01 by ccoers         #+#    #+#                */
/*   Updated: 2019/05/10 14:42:22 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int		i;
	char	*str;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * ft_intlen(nb) + 1);
	if (str == NULL)
		return (NULL);
	i = ft_intlen(nb) - 1;
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
