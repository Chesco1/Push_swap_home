/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:44:14 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:38:23 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	char		*line;
	t_stacks	*info;

	info = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	line = NULL;
	if (info == NULL)
		ft_error();
	if (argc <= 1)
		exit(0);
	fill_struct(argc, argv, info);
	check_duplicate(info);
	while (get_next_line(0, &line) != 0)
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
