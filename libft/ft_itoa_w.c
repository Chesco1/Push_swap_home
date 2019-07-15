/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_w.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 15:35:50 by ccoers         #+#    #+#                */
/*   Updated: 2019/05/27 17:10:59 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	place_padding_zeroes(char *str, int i, int width)
{
	while (i < width)
	{
		str[i] = '0';
		i++;
	}
}

char		*ft_itoa_w(long long int nb, int width)
{
	int		i;
	char	*str;

	if (nb == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	str = (char *)malloc(sizeof(char) * ft_max(ft_ll_intlen(nb), width) + 1);
	if (str == NULL)
		return (NULL);
	i = ft_ll_intlen(nb) - 1;
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
	place_padding_zeroes(str, ft_strlen(str), width);
	return (str);
}
