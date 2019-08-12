/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 17:23:02 by ccoers        #+#    #+#                 */
/*   Updated: 2019/01/30 10:59:11 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	tmp = lst;
	if (lst != NULL)
	{
		tmp = f(lst);
		tmp->next = ft_lstmap(lst->next, f);
	}
	return (tmp);
}
