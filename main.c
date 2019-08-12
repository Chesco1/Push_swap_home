/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 19:25:03 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/12 19:25:05 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int     handle_flags(int argc, char **argv, t_stacks *info)
{
    int flags;
    int i;
    int j;

    i = 1;
    flags = 0;
    while (i < argc)
    {
        if (argv[i][0] == '-' && (argv[i][1] == 'p' || argv[i][1] == 'p'))
        {
            j = 0;
            while (argv[i][j] != '\0')
            {
                if (argv[i][j] == 'c')
                    SHOW_COLOR = 1;
                if (argv[i][j] == 'p')
                    PRINT = 1;
                j++;
            }
            flags++;
        }
        i++;
    }
    return (flags);
}

static void     fill_struct(int argc, char **argv, t_stacks *info)
{
    int i;
    int j;
    t_list *to_push_to_a;
    t_list *to_push_to_b;

    to_push_to_a = ft_lstnew(NULL, 0);
    to_push_to_a = ft_lstnew(NULL, 0);
    i = 1;
    j = 0;
    PRINT = 0;
    SHOW_COLOR = 0;
    LAST_TO_A = 0;
    LAST_TO_B = 0;
    // flags = handle_flags(argc, argv, info);
    // LEN_A = argc - flags - 1;
	LEN_A = argc - 1;
    LEN_B = 0;
    A = (int *)malloc(sizeof(int) * LEN_A);
    B = (int *)malloc(sizeof(int) * LEN_A);
    LAST_OP = 0;
    while (i < argc)
    {
        A[j] = ft_atoi(argv[i]);
        j++;
        i++;
    }
}

int             main(int argc, char **argv)
{
    t_stacks *info;

    info = (t_stacks *)malloc(sizeof(t_stacks));
    fill_struct(argc, argv, info);
	initial_push(info);
	print_stacks(info);
    return (0);
}