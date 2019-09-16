/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:44:14 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/05 16:44:15 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    checker(int argc, char **argv)
{
    char *line;
    t_stacks *info;

    fill_struct(argc, argv, info);
    while (get_next_line(1, &line) > 0)
    {
        execute_command(info, line);
        free(line);
    }
    if (is_done(info) == 1)
        ft_putendl("OK");
    else
        ft_putendl("KO");
    return (0);
}