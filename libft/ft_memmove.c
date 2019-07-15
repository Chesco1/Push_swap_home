/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:29:24 by ccoers        #+#    #+#                 */
/*   Updated: 2019/01/31 12:17:45 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char *)dst;
	if (a < (unsigned char *)src)
	{
		i = 0;
		a = ft_memcpy(a, (unsigned char *)src, len);
		return (dst);
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			a[i] = ((unsigned char *)src)[i];
			i--;
		}
		return (dst);
	}
}
