/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_toupper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 18:39:09 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/27 12:53:40 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
