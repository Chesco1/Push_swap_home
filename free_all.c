/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_all.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:56:29 by svoort         #+#    #+#                */
/*   Updated: 2019/09/04 15:37:10 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_partitions(t_list *list)
{
    t_list  *prev;

    while (list)
    {
        prev = list;
        list = list->next;
		if (prev->content)
			free(prev->content);
		if (prev)
       		free(prev);
    }
}

void        free_all(t_stacks *info)
{
	if (A)
    	free(A);
	if (B)
    	free(B);
	if (info)
	{
    	free(info);
    	free_partitions(info->b_partitions);
	}
}
