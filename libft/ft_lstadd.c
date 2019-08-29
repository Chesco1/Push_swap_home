/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 16:34:09 by ccoers        #+#    #+#                 */
/*   Updated: 2019/01/30 14:32:34 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		*alst = (t_list *)malloc(sizeof(t_list));
		(*alst)->content = new->content;
		(*alst)->content_size = new->content_size;
		(*alst)->next = NULL;
		return ;
	}
	new->next = *alst;
	*alst = new;
}
