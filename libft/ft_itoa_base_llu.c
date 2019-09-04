/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_llu.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 12:43:30 by avan-rei       #+#    #+#                */
/*   Updated: 2019/09/04 15:33:34 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_base_llu(long long unsigned int nb,
		long long unsigned int base)
{
	int i;

	i = 1;
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base_llu(long long unsigned int nb,
		long long unsigned int base, char case_type)
{
	int		i;
	char	*str;
	char	tab[16];

	i = 0;
	if (case_type == 'l')
		ft_strcpy(tab, "0123456789abcdef");
	else
		ft_strcpy(tab, "0123456789ABCDEF");
	if (base < 2 || base > 16)
		return (0);
	i = ft_intlen_base_llu(nb, base);
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = tab[nb % base];
		i--;
		nb /= base;
	}
	return (str);
}
