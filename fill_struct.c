/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 18:10:11 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:16:50 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_print(char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'p' && argv[1][2] == '\0')
		return (1);
	return (0);
}

void		fill_struct(int argc, char **argv, t_stacks *info)
{
	int i;
	int j;

	B_PARTITIONS = NULL;
	INSTRUCTIONS = (t_list *)ft_memalloc(sizeof(t_list));
	PRINT = check_print(argv);
	i = 1 + PRINT;
	j = 0;
	SHOW_COLOR = 0;
	LEN_A = argc - 1;
	LEN_B = 0;
	A = (int *)ft_memalloc(sizeof(int) * LEN_A + 1);
	B = (int *)ft_memalloc(sizeof(int) * LEN_A + 1);
	if (INSTRUCTIONS == NULL || A == NULL || B == NULL)
		ft_error();
	LAST_OP = 0;
	LEFT_IN_PARTITION_A = LEN_A;
	while (i < argc)
	{
		A[j] = ps_atoi(argv[i]);
		j++;
		i++;
	}
}
