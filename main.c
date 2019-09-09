/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 19:25:03 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/04 17:58:01 by avan-rei      ########   odam.nl         */
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

void            print_instructions(t_stacks *info)
{
    t_list *current;

    current = INSTRUCTIONS;
    while (current != NULL)
    {
        if (current->content)
            ft_putendl(current->content);
        current = current->next;
    }
}

static void     fill_struct(int argc, char **argv, t_stacks *info)
{
    int i;
    int j;

    B_PARTITIONS = NULL;
    INSTRUCTIONS = (t_list *)ft_memalloc(sizeof(t_list));
    i = 1;
    j = 0;
    PRINT = 0;
    SHOW_COLOR = 0;
    // flags = handle_flags(argc, argv, info);
    // LEN_A = argc - flags - 1;
	LEN_A = argc - 1;
    LEN_B = 0;
    A = (int *)ft_memalloc(sizeof(int) * LEN_A + 1);
    B = (int *)ft_memalloc(sizeof(int) * LEN_A + 1);
    LAST_OP = 0;
    LEFT_IN_PARTITION_A = LEN_A;
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

    info = (t_stacks *)ft_memalloc(sizeof(t_stacks));
    fill_struct(argc, argv, info);
	initial_push(info);
	print_stacks(info);
    print_instructions(info);
    return (0);
}