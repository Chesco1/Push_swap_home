/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:59:17 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 14:47:50 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intdup(const int *array, int n)
{
	int *dest;

	dest = (int *)malloc(sizeof(int) * n);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, array, n * sizeof(int));
	return (dest);
}
