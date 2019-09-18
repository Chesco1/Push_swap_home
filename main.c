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

void            print_instructions(t_stacks *info)
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

void            delete_instructions(t_stacks *info)
{
    t_list *current;
   
    current = INSTRUCTIONS;
    while (current)
    {
        if (current->content == NULL)
            ft_lstunlink(&INSTRUCTIONS, current);
        current = current->next;
    }
    current = INSTRUCTIONS;   
    while (current->next != NULL)
    { 
        if ((ft_strequ(current->content, "pa") == 1 &&
        ft_strequ(current->next->content, "pb") == 1) || 
        (ft_strequ(current->content, "pb") == 1 && 
        ft_strequ(current->next->content, "pa") == 1))
        {
            ft_lstunlink(&INSTRUCTIONS, current);
            ft_lstunlink(&INSTRUCTIONS, current->next);
            current = INSTRUCTIONS;
            continue ;
        }
        current = current->next;
    }
}

int             main(int argc, char **argv)
{
    t_stacks *info;

    info = (t_stacks *)ft_memalloc(sizeof(t_stacks));
    fill_struct(argc, argv, info);
    check_duplicate(info);
    if (is_done(info) == 0)
    {
	    initial_push(info);
        delete_instructions(info);
        print_instructions(info);
    //  print_stacks(info);
    }
    return (0);
}