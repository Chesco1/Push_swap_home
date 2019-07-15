/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_median.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 13:21:58 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/07 13:22:02 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     find_nbr_n(int *values, int len, int n)
{
	int result;
	int *copy;

	copy = (int *)malloc(sizeof(int) * len);
	ft_memcpy(copy, values, len * sizeof(int));
	bubble_sort(copy, len, 'a');
	if (n <= len)
	{
		result = copy[n - 1];
		free(copy);
		return (result);
	}
	else
	{
		free(copy);
		write(2, "Find_nbr_n error: Array consists of less then n integers. Stop", 63);
		exit(1);
	}
}