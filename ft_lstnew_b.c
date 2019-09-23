/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 13:57:25 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 14:28:02 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_b(void *content, size_t content_size)
{
	t_list *lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = content_size;
	}
	else
	{
		lst->content = (char *)ft_strdup(content);
		if (lst->content == NULL)
			return (0);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
