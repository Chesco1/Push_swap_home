/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 12:52:09 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:13:56 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_next_b(t_stacks *info, int i)
{
	int j;

	j = ft_min(LEN_B - LEN_A, 0);
	if (i >= LEN_A - LEN_B)
	{
		if (i + j == 1 && (LAST_OP == 2 || LAST_OP == 3))
			ft_printf("%{$RED}=13i", B[i + j]);
		else if (i + j > 0 && (LAST_OP == 10 || LAST_OP == 11))
			ft_printf("%{$RED}=13i", B[i + j]);
		else if (i + j == LEN_B - 1 && (LAST_OP == 7 || LAST_OP == 8))
			ft_printf("%{$RED}=13i", B[i + j]);
		else if (i + j == 0 && (LAST_OP == 2 || LAST_OP == 3))
			ft_printf("%{$GREEN}=13i", B[i + j]);
		else if (i + j == 0 && (LAST_OP == 10 || LAST_OP == 11))
			ft_printf("%{$GREEN}=13i", B[i + j]);
		else if (i + j != LEN_A - 1 && (LAST_OP == 7 || LAST_OP == 8))
			ft_printf("%{$GREEN}=13i", B[i + j]);
		else if (i + j == 0 && LAST_OP == 5)
			ft_printf("%{$BLUE}=13i", B[i + j]);
		else
			ft_printf("%{$WHITE}=13i", B[i + j]);
	}
	else
		ft_printf("%=13c", ' ');
}

static void		print_next_a(t_stacks *info, int i)
{
	int j;

	j = ft_min(LEN_A - LEN_B, 0);
	if (i >= LEN_B - LEN_A)
	{
		if (i + j == 1 && (LAST_OP == 1 || LAST_OP == 3))
			ft_printf("%{$RED}=13i", A[i + j]);
		else if (i + j > 0 && (LAST_OP == 9 || LAST_OP == 11))
			ft_printf("%{$RED}=13i", A[i + j]);
		else if (i + j == LEN_A - 1 && (LAST_OP == 6 || LAST_OP == 8))
			ft_printf("%{$RED}=13i", A[i + j]);
		else if (i + j == 0 && (LAST_OP == 1 || LAST_OP == 3))
			ft_printf("%{$GREEN}=13i", A[i + j]);
		else if (i + j == 0 && (LAST_OP == 9 || LAST_OP == 11))
			ft_printf("%{$GREEN}=13i", A[i + j]);
		else if (i + j != LEN_A - 1 && (LAST_OP == 6 || LAST_OP == 8))
			ft_printf("%{$GREEN}=13i", A[i + j]);
		else if (i + j == 0 && LAST_OP == 4)
			ft_printf("%{$BLUE}=13i", A[i + j]);
		else
			ft_printf("%{$WHITE}=13i", A[i + j]);
	}
	else
		ft_printf("%=13c", ' ');
}

void			print_stacks(t_stacks *info)
{
	int i;

	i = 0;
	write(1, "\n", 1);
	while (i < ft_max(LEN_A, LEN_B))
	{
		ft_printf("|");
		print_next_a(info, i);
		ft_printf("|");
		print_next_b(info, i);
		ft_printf("|\n");
		i++;
	}
	ft_putendl("=============================");
	ft_printf("||  Stack %{$WHITE}c%{RESET}sStack \
	%{$WHITE}c  %{RESET}s\n", 'A', "   |   ", 'B', "||");
	ft_putendl("=============================");
}
