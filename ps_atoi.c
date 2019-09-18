/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:27 by ccoers        #+#    #+#                 */
/*   Updated: 2019/09/18 17:05:27 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sign(const char *str, int *i, long long *sign)
{
	if (str[(*i)] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[(*i)] == '+')
		(*i)++;
}

int			ps_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	result;
	long long	big_int;

	i = 0;
	sign = 1;
	result = 0;
	big_int = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' ||
		str[i] == '\v' || str[i] == ' ' || str[i] == '\r')
		i++;
	check_sign(str, &i, &sign);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		result = (result * 10) + (str[i] - '0');
		if ((sign == -1 && result > -FT_INT_MIN) ||
			(sign != -1 && result > FT_INT_MAX))
			ft_error();
		i++;
		big_int++;
	}
	return (result * sign);
}