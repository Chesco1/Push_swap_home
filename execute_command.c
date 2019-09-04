/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:53:05 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/02 17:15:44 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    handle_error(t_stacks *info)
{
    write(2, "Error\n", 6);
	if (A)
    	free(A);
	if (B)
    	free(B);
	if (info)
    	free(info);
    exit(2);
}

void    execute_command(t_stacks *info, char *command)
{
    if (ft_strequ(command, "sa") == 1)
        swap_a(info);
    else if (ft_strequ(command, "sb") == 1)
        swap_b(info);
    else if (ft_strequ(command, "ss") == 1)
        swap_both(info);
    else if (ft_strequ(command, "pa") == 1)
        push_a(info);
    else if (ft_strequ(command, "pb") == 1)
        push_b(info);
    else if (ft_strequ(command, "ra") == 1)
        rotate_a(info);
    else if (ft_strequ(command, "rb") == 1)
        rotate_b(info);
    else if (ft_strequ(command, "rr") == 1)
        rotate_both(info);
    else if (ft_strequ(command, "rra") == 1)
        reverse_rotate_a(info);
    else if (ft_strequ(command, "rrb") == 1)
        reverse_rotate_b(info);
    else if (ft_strequ(command, "rrr") == 1)
        reverse_rotate_both(info);
    else
	{
        ft_printf("command before error: %s", command);
        handle_error(info);
	}
}