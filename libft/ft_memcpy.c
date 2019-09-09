/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 15:29:42 by ccoers        #+#    #+#                 */
/*   Updated: 2019/01/31 12:18:15 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*s2;

	s = dst;
	s2 = (void *)src;
	i = 0;
	while (i < n)
	{
		s[i] = s2[i];
		i++;
	}
	return (dst);
}
