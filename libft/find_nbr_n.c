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

static void		print_error_message(int len, int n)
{
	if (n == 1)
		ft_printf("Find_nbr_n error: Looking for first item in array of size \
		%i. Stop\n", len);
	else if (n == 2)
		ft_printf("Find_nbr_n error: Looking for second item in array of size \
		%i. Stop\n", len);
	else if (n == 3)
		ft_printf("Find_nbr_n error: Looking for third item in array of size \
		%i. Stop\n", len);
	else
		ft_printf("Find_nbr_n error: Looking for %ith item in array of size \
		%i. Stop\n", n, len);
}

int     		find_nbr_n(int *values, int len, int n)
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
		print_error_message(len, n);
		exit(1);
	}
}