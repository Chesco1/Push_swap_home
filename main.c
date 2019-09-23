/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 19:25:03 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 17:04:16 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_instructions(t_stacks *info)
{
	t_list *current;
	t_list *to_free;

	current = INSTRUCTIONS;
	while (current != NULL)
	{
		if (current->content)
			ft_putendl(current->content);
		to_free = current;
		current = current->next;
		ft_lstunlink(&INSTRUCTIONS, to_free);
	}
}

static void		delete_instructions_2(t_stacks *info, t_list *next)
{
	t_list *current;

	current = INSTRUCTIONS;
	while (current->next != NULL)
	{
		next = current->next;
		if ((ft_strequ(current->content, "pa") == 1 &&
		ft_strequ(current->next->content, "pb") == 1) ||
		(ft_strequ(current->content, "pb") == 1 &&
		ft_strequ(current->next->content, "pa") == 1))
		{
			ft_lstunlink(&INSTRUCTIONS, current->next);
			ft_lstunlink(&INSTRUCTIONS, current);
			current = INSTRUCTIONS;
			continue ;
		}
		current = next;
	}
}

void			delete_instructions(t_stacks *info)
{
	t_list *current;
	t_list *next;

	current = INSTRUCTIONS;
	while (current)
	{
		next = current->next;
		if (current->content == NULL)
			ft_lstunlink(&INSTRUCTIONS, current);
		current = next;
	}
	delete_instructions_2(info, next);
}

int				main(int argc, char **argv)
{
	t_stacks *info;

	info = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	if (info == NULL)
		ft_error();
	fill_struct(argc, argv, info);
	check_duplicate(info);
	if (is_done(info) == 0)
	{
		initial_push(info);
		delete_instructions(info);
		print_instructions(info);
	}
	free(A);
	free(B);
	free(info);
	return (0);
}
